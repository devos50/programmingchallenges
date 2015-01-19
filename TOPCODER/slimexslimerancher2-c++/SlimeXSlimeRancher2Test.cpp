#include "SlimeXSlimeRancher2.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SlimeXSlimeRancher2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    SlimeXSlimeRancher2 solution;

    void testCase0() {
        int attributes_[] = {1, 2, 3};
        vector<int> attributes(attributes_, attributes_ + (sizeof(attributes_) / sizeof(attributes_[0])));
		int expected_ = 3;
        assertEquals(0, expected_, solution.train(attributes));
    }

    void testCase1() {
        int attributes_[] = {5, 5};
        vector<int> attributes(attributes_, attributes_ + (sizeof(attributes_) / sizeof(attributes_[0])));
		int expected_ = 0;
        assertEquals(1, expected_, solution.train(attributes));
    }

    void testCase2() {
        int attributes_[] = {900, 500, 100};
        vector<int> attributes(attributes_, attributes_ + (sizeof(attributes_) / sizeof(attributes_[0])));
		int expected_ = 1200;
        assertEquals(2, expected_, solution.train(attributes));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 3; i++) {
        SlimeXSlimeRancher2Test test;
        test.runTest(i);
    }
}
