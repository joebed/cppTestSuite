# CPP TestSuite

Lightweight unit testing framework

The idea is to make this similar to pytest with time, I've learned a lot on this project with macros and console output.
Further plans for this project include a more streamlined results system, speeding it up because I KNOW this boy is going to be slow on big tests, maybe creating a thread for each test case and operating them simulataneously? This would be helpful for async functions

## Usage
Make sure to #include "suite.cpp" at the top of your file. All of these functions will go directly into your main function. 

The first line in your function should be 
<RUN_TESTS(bool)>
This sets up the test suite. The bool is a flag for verbose: by including it the program will give you the failed test cases right before the end test line.

After RUN_TESTS, follow the following format for your tests:
```
TEST(string) {
    ...
    ASSERT(bool)
}
```

TEST sets up the TestCase with the chosen name and ASSERT will run the test case. By doing this, the TestSuite will keep track of which and how test cases you fail, and will tell you at the end of the output. See example.cpp in the repo for an example. 