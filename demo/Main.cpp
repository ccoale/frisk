#include <iostream>
#include "../inc/Frisk.h"
#include "../inc/ConsoleReporter.h"

int mult(int x, int y) { return x * y; }

DEF_TEST(mult_test)
{
  BEGIN_TEST(self);

  self.setOption(FRISK_OPTION_CONTINUE, true);

  EXPECT_EQUAL(self, mult(0, 0), 0, "0 times anything should be 0");
  EXPECT_EQUAL(self, mult(0, 5), 0, "0 times anything should be 0");
  EXPECT_EQUAL(self, mult(5, 0), 0, "0 times anything should be 0");
  EXPECT_EQUAL(self, mult(1, 5), 5, "1 times anything is itself");
  EXPECT_EQUAL(self, mult(5, 1), 5, "1 times anything is itself");
  EXPECT_EQUAL(self, mult(5, 5), 25, "5 times itself is its square");
  EXPECT_EQUAL(self, mult(1, -5), -5, "1 times a negative number is that negative number");
  EXPECT_EQUAL(self, mult(-5, 1), -5, "1 times a negative number is that negative number");
  EXPECT_GREATER(self, mult(-5, -5), 0, "Two negatives mutlipled should be positive.");
  EXPECT_LESS(self, mult(-5, 5), 0, "One negative times one positive should be negative.");
}

int main()
{
	Frisk::TestCollection tests;
  tests.addTest(mult_test, "mult_test");

	Frisk::ConsoleReporter reporter;
  reporter.setOption("description", true);
	std::list<Frisk::Test> results = tests.runTests(false, &reporter);

	return 1;
}
