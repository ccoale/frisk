#Overview
Frisk is a simple but powerful Test Driven Development (TDD) framework for C++ projects of all sizes. TDD is an excellent development ideology in which the developer first writes tests and then writes code in order to satisfy the tests. It prevents horrible bugs from becoming deeply embedded in large projects and allows the debugging and isolation of problematic code before it is pushed to production.

The TDD process typically follows this standard routine: 

1. Design an interface/feature.
2. Design and write a test that thoroughly tests all cases, especially corner cases, of the interface.
3. Execute the test and determine which tests fail and which succeed.
4. If a test fails, change or add implementation so that the test no longer fails. If it fails, go back to test 3. If it passes, move on to the next test. 
5. If all tests succeed, you have successfully implemented the interface/features.

Of course, if at a later time you realize you need additional tests, simply write more tests for the interface and repeat steps 3 through 5. (Although, ideally, code should conform to tests, not the other way around.)

#How Tests Work
Frisk tests are very simple concepts. They are simply functions that do not return any value, but rather assert expectations. For example, you can write a simple a simple test that verifies that your add function works correctly:

```C++
void test_add(Frisk::Test &self)
{
  self.ExpectEquals(add(5, 5), 10, "Doubling a number");
  self.ExpectEquals(add(10, 12), 22, "Adding two even numbers");
  self.ExpectEquals(add(3, 5), 8, "Adding two odd numbers");
  self.ExpectEquals(add(3, 6), 9, "Adding one even and one odd number");
  self.ExpectEquals(add(-2, 10), 8, "Adding a negative number to a positive number");
 
}
```

When Frisk runs this test (this is considered just one test with multiple expectations), it will check to make sure all of the expectations are met. If any expectation is NOT met, then it will display the provided message that corresponds to the failed expectation as well as an indication that it failed. For example, it might display:

"FAILED 'add' TEST: Adding two odd numbers"

This shows that our test named 'add' failed because it did not add two odd numbers correctly. While it may seem strange to have a "BeginTest" and "EndTest" function call inside the test, it is important because it allows the framework to internally initialize a given test and also stack error results. The BeginTest function also allows for configuration of how errors should be handled (i.e. quit at first error, continue to last, etc.). 


#Powerful
The power of Frisk lies in its ability to handle many configurations of tests. Below is a list of some of the features that make Frisk an amazing TDD framework:

1. Large variety of expectations (equality, inequality, logical comparisons, bitwise comparisons) on a variety of types of data (arrays, ranges, strings, numbers, etc.)
2. The ability to customize how failed tests are handled (i.e. critical -- stop testing and emphasize this failure, warning -- simply give a warning and continue, etc.)
3. The ability to group tests into "test suites" and the ability to control how failed test suites are handled.
4. Much more!
