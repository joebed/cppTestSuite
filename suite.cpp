#include <iostream>
#include <string>
#include <vector>

class TestSuite {
public:
    // REQUIRES: bool, verbose will print the cases failed at the end of execution
    // EFFECTS: sets up test suite to start
    TestSuite(bool v) : verbose(v) {
        std::cout << "\n===================TESTING START===================\n";
        numFailed = 0;
        numPassed = 0;
        curr = TestCase("");
        failed = {};
    }
    ~TestSuite() {
        printResults();
    }
    void printResults() {
        int total = numFailed + numPassed;
        std::cout << "\033[1m======================RESULTS======================\033[0m\n";
        double ratio = numPassed * 1.0 / total;
        if (ratio < 0.5) std::cout << "\033[31m";
        else if (ratio < 1) std::cout << "\033[33m";
        else std::cout << "\033[32m";
        std::cout << "Passed " << numPassed << " / " << total << "\033[0m";
        if (total == numPassed) std::cout << "\nPARTY TIME WOO WOO!!!\n";
        else {
            std::cout << "\nOhhhhhh looks like some cases failed:\n";
            std::cout << "\033[31m======================FAILURES=====================\033[0m\n";

            for (std::string f : this->failed) {
                std::cout << f << "\n";
            }
        }
        std::cout << "====================TESTING END====================\n";
    }
    void makeTest(const std::string &n) {
        this->curr = TestCase(n);
    }
    void assert(bool exp) {
        if (this->curr.assert(exp, this->verbose)) {
            ++numFailed;
            failed.push_back(this->curr.getName());
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
        int assert(bool exp, bool verbose) {
            if (exp){
                if (verbose) {
                    std::cout << "\033[32mPASSED: " << this->name << "\033[0m\n";
                }
                else {
                    std::cout << "\033[32m.\033[0m";
                }
                return 0;
            }
            else {
                if (verbose) {
                    std::cout << "\033[31mFAILED: " << this->name << "\033[0m\n";
                }
                else {
                    std::cout << "\033[31mF\033[0m";
                }
                return 1;
            }
        }
    private:
        std::string name;
    };
    TestCase curr;
};

#define RUN_TESTS(verbose) TestSuite dawg(verbose);
// TODO: Implicitly create a TestSuite in case RUN_TESTS not included in main

#define TEST(name) dawg.makeTest(name);
// TODO: Allow testing for equality of sequences, greater than, less than, double comparison to a set precision by function call

#define ASSERT(exp) dawg.assert(exp);

#define ASSERT_SEQUENCE()