#include "ShoutterDiv2.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class ShoutterDiv2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ShoutterDiv2 solution;

    void testCase0() {
        int s_[] = {1, 2, 4};
        vector<int> s(s_, s_ + (sizeof(s_) / sizeof(s_[0])));
        int t_[] = {3, 4, 6};
        vector<int> t(t_, t_ + (sizeof(t_) / sizeof(t_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.count(s, t));
    }

    void testCase1() {
        int s_[] = {0};
        vector<int> s(s_, s_ + (sizeof(s_) / sizeof(s_[0])));
        int t_[] = {100};
        vector<int> t(t_, t_ + (sizeof(t_) / sizeof(t_[0])));
		int expected_ = 0;
        assertEquals(1, expected_, solution.count(s, t));
    }

    void testCase2() {
        int s_[] = {0, 0, 0};
        vector<int> s(s_, s_ + (sizeof(s_) / sizeof(s_[0])));
        int t_[] = {1, 1, 1};
        vector<int> t(t_, t_ + (sizeof(t_) / sizeof(t_[0])));
		int expected_ = 3;
        assertEquals(2, expected_, solution.count(s, t));
    }

    void testCase3() {
        int s_[] = {9, 26, 8, 35, 3, 58, 91, 24, 10, 26, 22, 18, 15, 12, 15, 27, 15, 60, 76, 19, 12, 16, 37, 35, 25, 4, 22, 47, 65, 3, 2, 23, 26, 33, 7, 11, 34, 74, 67, 32, 15, 45, 20, 53, 60, 25, 74, 13, 44, 51};
        vector<int> s(s_, s_ + (sizeof(s_) / sizeof(s_[0])));
        int t_[] = {26, 62, 80, 80, 52, 83, 100, 71, 20, 73, 23, 32, 80, 37, 34, 55, 51, 86, 97, 89, 17, 81, 74, 94, 79, 85, 77, 97, 87, 8, 70, 46, 58, 70, 97, 35, 80, 76, 82, 80, 19, 56, 65, 62, 80, 49, 79, 28, 75, 78};
        vector<int> t(t_, t_ + (sizeof(t_) / sizeof(t_[0])));
		int expected_ = 830;
        assertEquals(3, expected_, solution.count(s, t));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 4; i++) {
        ShoutterDiv2Test test;
        test.runTest(i);
    }
}
