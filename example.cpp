#include <iostream>
#include "suite.cpp"

// Easy example to see how the macros work
// USE: RUN_TESTS(verbose) must be included in start of program to initialize TestSuite
// TEST takes in a string for a name, ASSERT should be the last line in every TEST case and must evaluate to a boolean

int inc(int x) {
    return x + 2;
}

// Comment out the failing test cases to see how output changes color for easy grasp at how your code is doing
int main() {
    RUN_TESTS(true)

    // Passes
    TEST("bruh") {
        int x = 5;
        ASSERT(x == 5)
    }

    // Fails
    TEST("nah fam") {
        int x = 4;
        ASSERT(inc(x) == 5)
    }

    // Fails
    TEST("nah fam6") {
        int x = 4;
        ASSERT(inc(x) == 5)
    }
    return 0;
}