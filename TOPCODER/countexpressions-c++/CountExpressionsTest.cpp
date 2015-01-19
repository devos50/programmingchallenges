#include "CountExpressions.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class CountExpressionsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    CountExpressions solution;

    void testCase0() {
		int x = 7;
		int y = 8;
		int val = 16;
		int expected_ = 9;
        assertEquals(0, expected_, solution.calcExpressions(x, y, val));
    }

    void testCase1() {
		int x = 3;
		int y = 5;
		int val = 7;
		int expected_ = 5;
        assertEquals(1, expected_, solution.calcExpressions(x, y, val));
    }

    void testCase2() {
		int x = 99;
		int y = 100;
		int val = 98010000;
		int expected_ = 6;
        assertEquals(2, expected_, solution.calcExpressions(x, y, val));
    }

    void testCase3() {
		int x = -99;
		int y = 42;
		int val = -1764;
		int expected_ = 2;
        assertEquals(3, expected_, solution.calcExpressions(x, y, val));
    }

    void testCase4() {
		int x = 100;
		int y = -100;
		int val = -100000000;
		int expected_ = 0;
        assertEquals(4, expected_, solution.calcExpressions(x, y, val));
    }

    void testCase5() {
		int x = 1;
		int y = 2;
		int val = 5;
		int expected_ = 17;
        assertEquals(5, expected_, solution.calcExpressions(x, y, val));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 6; i++) {
        CountExpressionsTest test;
        test.runTest(i);
    }
}
