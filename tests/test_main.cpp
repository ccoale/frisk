#include <Frisk.h>
#include <ConsoleReporter.h>

// These test the primitive expectations (EXPECT_EQUAL, etc.)
#include "primitive_tests.h"

int main(int argc, char *argv[])
{
  Frisk::TestCollection tests;
  Frisk::ConsoleReporter reporter;
  reporter.setOption("verbose", true);
  reporter.setOption("description", true);

  initializePrimitiveTests(tests);
  
  std::list<Frisk::Test> results = tests.runTests(false, &reporter);
  return tests.getLastFailCount();
}
