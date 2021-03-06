import CppHeaderParser
import argparse
import sys
import os
import time

def buildFileList(baseDir):
  resultList = []
  for root, dirs, files in os.walk(baseDir):
    for fileName in files:
      if (fileName.endswith(".h") or fileName.endswith(".hpp")):
        fullPath = os.path.join(root, fileName)
        resultList.append(fullPath)
  return resultList

def functionInDictionary(dictionary, funcName):
  for key in dictionary.keys():
    if funcName in dictionary[key]:
      return True

  return False

def buildFunctionDictionary(filePaths):
  result = {}
  # result["filePath"] = [list of functions]
  for filePath in filePaths:
    try:
      cppHeader = CppHeaderParser.CppHeader(filePath)
    except CppHeaderParser.CppParserError as e:
      print("[SKIPPED " + filePath + "]: " + str(e))
      continue
    
    result[filePath] = []
    # First get bare functions:
    for func in cppHeader.functions:
      realName = ""      
      namespace = func["namespace"]
      if (namespace != ""):
        realName += namespace + "_"

      realName += func["name"]
      tempName = realName

      for i in range(2, 100):
        if (functionInDictionary(result, tempName)):
          tempName = realName + str(i)
        else:
          result[filePath].append(tempName)
          break

    # Now go through all class methods (public, private, and protected)
    for fileClass in cppHeader.classes:
      for accessLevel in ["public", "private", "protected"]:
        for method in cppHeader.classes[fileClass]["methods"][accessLevel]:
          methodName = method["name"]
          if (method["destructor"]):
            methodName = method["name"] + "_Destructor"
          elif (method["constructor"]):
            methodName = method["name"] + "_Constructor"

          namespaceName = method["namespace"]
          namespaceName = namespaceName.replace("::", "_")
          if (namespaceName != ""):
            realMethodName = namespaceName + fileClass + "_" + methodName
          else:
            realMethodName = fileClass + "_" + methodName

          tempName = realMethodName
          if ("<" in tempName or ">" in tempName or method["name"].startswith("operator")):
            continue # prevent buggy template parsing...

          for i in range(2, 100):
            if (functionInDictionary(result, tempName)):
              tempName = realMethodName + str(i)
            else:
              result[filePath].append(tempName)
              break

  return result

# Creates the tests directory structure for the     
def createTests(funcDict, targetDir, sourceDir):
  absTargetPath = os.path.abspath(targetDir)
  absSourcePath = os.path.abspath(sourceDir)

  mainOutFile = open(os.path.join(absTargetPath, "test_main.cpp"), "w")
  mainOutFileSource = "#include <Frisk.h>\n#include <TestCollection.h>\n#include <ConsoleReporter.h>\n"
  mainFuncSource = "\n\nint main(int argc, char *argv[])\n{\n"
  mainFuncSource += "  Frisk::TestCollection testCollection;\n"
  mainFuncSource += "  Frisk::ConsoleReporter reporter;\n\n"

  for filePath in funcDict.keys():
    if (len(funcDict[filePath]) == 0):
      continue

    localPath = filePath[len(absSourcePath):]
    testPath = absTargetPath + localPath
    rootPath, testFileName = os.path.split(testPath)
    testFileName = "test_" + testFileName
    realTestPath = os.path.join(rootPath, testFileName)

    
    #print("Real test path: " + realTestPath)
    if not os.path.exists(os.path.dirname(realTestPath)):
      os.makedirs(os.path.dirname(realTestPath))
    
    relativeIncludeName = os.path.relpath(filePath, os.path.dirname(realTestPath))

    outFile = open(realTestPath, "w")
    
    mainOutFileSource += '#include "' + os.path.relpath(realTestPath, absTargetPath) + '"' + "\n"

    # include lines.
    outFile.write("#include <Frisk.h>\n")
    outFile.write('#include "' + relativeIncludeName + '"' + "\n\n")
    outFile.write("namespace FriskTests\n{\n")
    for funcName in funcDict[filePath]:
      outFile.write("    DEF_TEST(" + funcName + "_test);\n")
      outFile.write("    DEF_TEST(" + funcName + "_test)\n")
      outFile.write("    {\n")
      outFile.write("      BEGIN_TEST(self);\n")
      outFile.write("      TEST_OPTION(self, FRISK_OPTION_PENDING, true);\n")
      outFile.write("      /* implement your tests for " + funcName.replace("_", "::") + "! */\n")
      outFile.write("    }\n\n")

      mainFuncSource += "  testCollection.addTest(FriskTests::" + funcName + "_test, " + '"' + funcName.replace("_", "::") + '");' + "\n"

    outFile.write("}")
    
    outFile.close()
    #print("Relative: " + relativeIncludeName)

  mainFuncSource += "    testCollection.runTests(false, &reporter);\n"
  mainFuncSource += "}\n"
  mainOutFile.write(mainOutFileSource)
  mainOutFile.write(mainFuncSource)
  mainOutFile.close()

t = time.time()
parser = argparse.ArgumentParser(description="Generates test files based on an already existing source.")

parser.add_argument("-s", "--source", type=str, nargs=1, required=True, help="The root source directory for the project in which you plan to create tests.")
parser.add_argument("-t", "--target", type=str, nargs=1, default="./tests", help="The target directory where you wish to have test files generated and stored.")

args = parser.parse_args()
source = list(args.source)[0]
target = list(args.target)[0]

fileList = buildFileList(source)
res = buildFunctionDictionary(fileList)
for filePath in res.keys():
  print("Generating tests for '" + filePath + "':")
  for funcName in res[filePath]:
    print("\tAdded test... '" + funcName.replace("_", "::") + "'.")

createTests(res, target, source)

print("Finished in " + str(time.time() - t) + " seconds.")

      
