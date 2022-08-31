#include <iostream>
#include <string>
#include <vector>

class TestSuite {
public:
    TestSuite(bool v) : verbose(v) {
        std::cout << "\n===================TESTING START===================\n\n";
        numFailed = 0;
        numPassed = 0;
        curr = TestCase("");
        failed = {};
    }
    ~TestSuite() {
        int total = numFailed + numPassed;
        std::cout << "\n\033[1m**** Results ****\033[0m\n";
        double ratio = numPassed * 1.0 / total;
        if (ratio < 0.5) std::cout << "\033[31m";
        else if (ratio < 1) std::cout << "\033[33m";
        else std::cout << "\033[32m";
        std::cout << "Passed " << numPassed << " / " << total << "\033[0m";
        if (this->verbose) {
            if (total == numPassed) std::cout << "\nPARTY TIME WOO WOO!!!";
            else {
                std::cout << "\nOhhhhhh looks like some cases failed:\n";
                for (std::string f : this->failed) {
                    std::cout << f << "\n";
                }
            }
        }
        std::cout << "\n====================TESTING END====================\n";
    }
    void makeTest(const std::string &n) {
        this->curr = TestCase(n);
    }
    void assert(bool exp) {
        if (this->curr.assert(exp)) {
            ++numFailed;
            if (this->verbose) failed.push_back(this->curr.getName());
        }
        else {
            ++numPassed;
        }
    }

private:
    bool verbose;
    int numPassed;
    int numFailed;
    std::vector<std::string> failed;
    class TestCase {
    public:
        TestCase() : name("") {};
        TestCase(const std::string &n) : name(n) {};
        std::string getName() {
            return name;
        }
        int assert(bool exp) {
            if (exp){
                std::cout << "\033[32mPASSED: " << this->name << "\033[0m\n";
                return 0;
            }
            else {
                std::cout << "\033[31mFAILED: " << this->name << "\033[0m\n";
                return 1;
            }
        }
    private:
        std::string name;
    };
    TestCase curr;
};

#define RUN_TESTS(verbose) TestSuite dawg(verbose);

#define TEST(name) dawg.makeTest(name);

#define ASSERT(exp) dawg.assert(exp);