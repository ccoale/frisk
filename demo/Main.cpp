#include <iostream>
#include "../inc/Frisk.h"
#include "../inc/ConsoleReporter.h"

DEF_TEST(myAddTest)
{
	BEGIN_TEST(self);
	self.setOption(FRISK_OPTION_CONTINUE, true);
	self.setOption(FRISK_OPTION_PENDING, true);
	EXPECT_EQUAL(self, (10 + 15), 15, "make sure a + b works");
	EXPECT_EQUAL(self, (10 + 10), 25, "make sure a + a is actually 2a");
}

DEF_TEST(myArrayTest)
{
	BEGIN_TEST(self);
	self.setOption(FRISK_OPTION_CONTINUE, true);
	self.setOption(FRISK_OPTION_QUIET, true);
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 1, 2, 4 };
	EXPECT_ARRAY_NOTEQUAL(self, arr1, arr2, 3, 3, "make sure arrays are not equal");

	std::string str1 = "hello world";
	std::string str2 = "goodbye world";
	EXPECT_LENGTH_EQUAL(self, str1, str2, "lengths should be the same");
	EXPECT_CSTRING_LENGTH_EQUAL(self, "heffllo", "world", "length should be the same");
}

int main()
{
	Frisk::TestCollection tests;
	tests.addTest(myAddTest, "myAddTest");
	tests.addTest(myArrayTest, "myArrayTest");
	Frisk::ConsoleReporter reporter;
	std::list<Frisk::Test> results = tests.runTests(false, &reporter);

	return 0;
}
