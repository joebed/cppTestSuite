#include <iostream>
#include "env.cpp"
using namespace std;
 
// TEST(true_is_true) {
//   ASSERT_TRUE(true);
// }

// TEST(numbers_are_equal) {
//   ASSERT_EQUAL(42, 42);
// }

// TEST_MAIN()

int inc(int x) {
    return x + 2;
}

int main() {
    RUN_TESTS(true)
    TEST("bruh") {
        int x = 5;
        ASSERT(x == 5)
    }
    TEST("nah fam") {
        int x = 4;
        ASSERT(inc(x) == 5)
    }
    TEST("nah fam6") {
        int x = 4;
        ASSERT(inc(x) == 5)
    }
    return 0;
}