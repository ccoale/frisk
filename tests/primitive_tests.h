#ifndef _PRIMITIVE_TESTS_H
#define _PRIMITIVE_TESTS_H

#include <Frisk.h>
#include <string>
#include <iostream>

DEF_TEST(expectEqualTest)
{
  BEGIN_TEST(self);
  //TEST_OPTION(self, FRISK_OPTION_PENDING, true);

  int a = 5, b = 5;
  float x = 0.5f, y = 0.5f;
  std::string c = "test", d = "test";
  char testArr1[5] = {'a', 'b', 'c', 'd', 'e'};
  char testArr2[5] = {'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQUAL(self, a, b, "integer equality should work");
  EXPECT_EQUAL(self, x, y, "floating-point equality should work");
  EXPECT_EQUAL(self, c, d, "std::string equality should work");

  for (int i = 0; i < 5; i++)
  {
    EXPECT_EQUAL(self, testArr1[i], testArr2[i], "character equality should work in a loop");
  }
}

DEF_TEST(expectNotEqualTest)
{
  BEGIN_TEST(self);
  //TEST_OPTION(self, FRISK_OPTION_PENDING, true);

  int a = 5, b = 4;
  float x = 0.3f, y = 0.5f;
  std::string c = "test55", d = "test";
  char testArr1[5] = {'b', 'b', 'c', 'd', 'e'};
  char testArr2[5] = {'a', 'e', 'i', 'b', 'f'};
  EXPECT_NOTEQUAL(self, a, b, "integer inequality should work");
  EXPECT_NOTEQUAL(self, x, y, "floating-point inequality should work");
  EXPECT_NOTEQUAL(self, c, d, "std::string inequality should work");

  for (int i = 0; i < 5; i++)
  {
    EXPECT_NOTEQUAL(self, testArr1[i], testArr2[i], "character inequality should work in a loop");
  }
}

DEF_TEST(expectGreaterTest)
{
  BEGIN_TEST(self);
  //TEST_OPTION(self, FRISK_OPTION_PENDING, true);

  int a = 5, b = 4;
  float x = 0.6f, y = 0.5f;
  char testArr1[5] = {'e', 'f', 'g', 'h', 'i'};
  char testArr2[5] = {'a', 'b', 'c', 'd', 'e'};
  EXPECT_GREATER(self, a, b, "> should work on integers");
  EXPECT_GREATER(self, x, y, "> should work on floats");

  for (int i = 0; i < 5; i++)
  {
    EXPECT_GREATER(self, testArr1[i], testArr2[i], "> should work for characters in a loop");
  }
}

DEF_TEST(expectGreaterOrEqualTest)
{
  BEGIN_TEST(self);
  //TEST_OPTION(self, FRISK_OPTION_PENDING, true);

  int a = 5, b = 4;
  float x = 0.5f, y = 0.5f;
  char testArr1[5] = {'e', 'f', 'g', 'h', 'i'};
  char testArr2[5] = {'e', 'f', 'c', 'd', 'i'};
  EXPECT_GREATER_OR_EQUAL(self, a, b, ">= should work on integers");
  EXPECT_GREATER_OR_EQUAL(self, x, y, ">= should work on floats");

  for (int i = 0; i < 5; i++)
  {
    EXPECT_GREATER_OR_EQUAL(self, testArr1[i], testArr2[i], ">= should work for characters in a loop");
  }
}

DEF_TEST(expectLessTest)
{
  BEGIN_TEST(self);
  //TEST_OPTION(self, FRISK_OPTION_PENDING, true);

  int b = 5, a = 4;
  float y = 0.6f, x = 0.5f;
  char testArr2[5] = {'e', 'f', 'g', 'h', 'i'};
  char testArr1[5] = {'a', 'b', 'c', 'd', 'e'};
  EXPECT_LESS(self, a, b, "< should work on integers");
  EXPECT_LESS(self, x, y, "< should work on floats");

  for (int i = 0; i < 5; i++)
  {
    EXPECT_LESS(self, testArr1[i], testArr2[i], "< should work for characters in a loop");
  }
}

DEF_TEST(expectLessOrEqualTest)
{
  BEGIN_TEST(self);
  //TEST_OPTION(self, FRISK_OPTION_PENDING, true);

  int b = 5, a = 4;
  float y = 0.5f, x = 0.5f;
  char testArr2[5] = {'e', 'f', 'g', 'h', 'i'};
  char testArr1[5] = {'e', 'f', 'c', 'd', 'i'};
  EXPECT_LESS_OR_EQUAL(self, a, b, "<= should work on integers");
  EXPECT_LESS_OR_EQUAL(self, x, y, "<= should work on floats");

  for (int i = 0; i < 5; i++)
  {
    EXPECT_LESS_OR_EQUAL(self, testArr1[i], testArr2[i], "<= should work for characters in a loop");
  }
}

DEF_TEST(expectTrueTest)
{
  BEGIN_TEST(self);
  
  int a = 5, b = 5;
  std::string c = "hello", d = "hello";
  float x = 0.5f, y = 0.4f;

  EXPECT_TRUE(self, a == b, "true test should work");
  EXPECT_TRUE(self, c == d, "true test should work");
  EXPECT_TRUE(self, x != y, "true test should work");
}

DEF_TEST(expectFalseTest)
{
  BEGIN_TEST(self);
  
  int a = 4, b = 5;
  std::string c = "hello", d = "goodbye";
  float x = 0.5f, y = 0.5f;

  EXPECT_FALSE(self, a == b, "false test should work");
  EXPECT_FALSE(self, c == d, "false test should work");
  EXPECT_FALSE(self, x != y, "false test should work");
}

void initializePrimitiveTests(Frisk::TestCollection &tests)
{
  tests.addTest(expectEqualTest, "EXPECT_EQUAL Test");
  tests.addTest(expectNotEqualTest, "EXPECT_NOTEQUAL Test");
  tests.addTest(expectLessTest, "EXPECT_LESS Test");
  tests.addTest(expectGreaterTest, "EXPECT_GREATER Test");
  tests.addTest(expectTrueTest, "EXPECT_TRUE Test");
  tests.addTest(expectFalseTest, "EXPECT_FALSE Test");
  tests.addTest(expectLessOrEqualTest, "EXPECT_LESSOREQUAL Test");
  tests.addTest(expectGreaterOrEqualTest, "EXPECT_GREATEROREQUAL Test");
}

#endif /* _PRIMITIVE_TESTS_H */
