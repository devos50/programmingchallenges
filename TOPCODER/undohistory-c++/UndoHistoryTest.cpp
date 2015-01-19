#include "UndoHistory.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class UndoHistoryTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    UndoHistory solution;

    void testCase0() {
        string lines_[] = {"tomorrow", "topcoder"};
        vector<string> lines(lines_, lines_ + (sizeof(lines_) / sizeof(lines_[0])));
		int expected_ = 18;
        assertEquals(0, expected_, solution.minPresses(lines));
    }

    void testCase1() {
        string lines_[] = {"a", "b"};
        vector<string> lines(lines_, lines_ + (sizeof(lines_) / sizeof(lines_[0])));
		int expected_ = 6;
        assertEquals(1, expected_, solution.minPresses(lines));
    }

    void testCase2() {
        string lines_[] = {"a", "ab", "abac", "abacus"};
        vector<string> lines(lines_, lines_ + (sizeof(lines_) / sizeof(lines_[0])));
		int expected_ = 10;
        assertEquals(2, expected_, solution.minPresses(lines));
    }

    void testCase3() {
        string lines_[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
        vector<string> lines(lines_, lines_ + (sizeof(lines_) / sizeof(lines_[0])));
		int expected_ = 39;
        assertEquals(3, expected_, solution.minPresses(lines));
    }

    void testCase4() {
        string lines_[] = {"ba", "a", "a", "b", "ba"};
        vector<string> lines(lines_, lines_ + (sizeof(lines_) / sizeof(lines_[0])));
		int expected_ = 13;
        assertEquals(4, expected_, solution.minPresses(lines));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 5; i++) {
        UndoHistoryTest test;
        test.runTest(i);
    }
}
