#Build Status
Each merge/push to master (and pull request) automatically runs a build using Travis-CI. Below is the build status of the last build (built using gmake, cmake, clang, and g++):
![Last build status](https://travis-ci.org/ccoale/frisk.svg)

#Overview
Frisk is a simple but powerful Test Driven Development (TDD) framework for C++ projects of all sizes. TDD is an excellent development ideology in which the developer first writes tests and then writes code in order to satisfy the tests. It prevents horrible bugs from becoming deeply embedded in large projects and allows the debugging and isolation of problematic code before it is pushed to production.

At the moment Frisk focuses specifically on unit-testing without mock objects.  Mock objects are a possible feature for a later version.

The TDD process typically follows this standard routine: 

1. Design an interface/feature.
2. Design and write a test that thoroughly tests all cases, especially corner cases, of the interface.
3. Execute the test and determine which tests fail and which succeed.
4. If a test fails, change or add implementation so that the test no longer fails. If it fails, go back to test 3. If it passes, move on to the next test. 
5. If all tests succeed, you have successfully implemented the interface/features.

Of course, if at a later time you realize you need additional tests, simply write more tests for the interface and repeat steps 3 through 5. (Although, ideally, code should conform to tests, not the other way around.)

#How Tests Work
Frisk tests are very simple concepts. They are simply functions that do not return any value, but rather assert expectations. For specific examples and documentation, please see the wiki pages.

#Powerful
The power of Frisk lies in its ability to handle many configurations of tests. Below is a list of some of the features that make Frisk an amazing TDD framework:

1. Large variety of expectations (equality, inequality, logical comparisons, bitwise comparisons) on a variety of types of data (arrays, ranges, strings, numbers, etc.)
2. The ability to customize how failed tests are handled (i.e. critical -- stop testing and emphasize this failure, warning -- simply give a warning and continue, etc.)
3. The ability to group tests into "test suites" and the ability to control how failed test suites are handled.
4. Much more!

(Added travis support test)
