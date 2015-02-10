# frisk
Frisk is a simple but powerful Test Driven Development (TDD) framework for C++ projects of all sizes. TDD is an excellent development ideology in which the developer first writes tests and then writes code in order to satisfy the tests. It prevents horrible bugs from becoming deeply embedded in large projects and allows the debugging and isolation of problematic code before it is pushed to production.

The TDD process typically follows this standard routine: 

1. Design an interface/feature.
2. Design and write a test that thoroughly tests all cases, especially corner cases, of the interface.
3. Execute the test and determine which tests fail and which succeed.
4. If a test fails, change or add implementation so that the test no longer fails. If it fails, go back to test 3. If it passes, move on to the next test. 
5. If all tests succeed, you have successfully implemented the interface/features.

Of course, if at a later time you realize you need additional tests, simply write more tests for the interface and repeat steps 3 through 5.
