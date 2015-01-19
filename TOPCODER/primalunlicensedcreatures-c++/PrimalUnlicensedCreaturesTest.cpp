#include "PrimalUnlicensedCreatures.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PrimalUnlicensedCreaturesTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    PrimalUnlicensedCreatures solution;

    void testCase0() {
		int initialLevel = 31;
        int grezPower_[] = {10, 20, 30};
        vector<int> grezPower(grezPower_, grezPower_ + (sizeof(grezPower_) / sizeof(grezPower_[0])));
		int expected_ = 3;
        assertEquals(0, expected_, solution.maxWins(initialLevel, grezPower));
    }

    void testCase1() {
		int initialLevel = 20;
        int grezPower_[] = {24, 5, 6, 38};
        vector<int> grezPower(grezPower_, grezPower_ + (sizeof(grezPower_) / sizeof(grezPower_[0])));
		int expected_ = 3;
        assertEquals(1, expected_, solution.maxWins(initialLevel, grezPower));
    }

    void testCase2() {
		int initialLevel = 20;
        int grezPower_[] = {3, 3, 3, 3, 3, 1, 25};
        vector<int> grezPower(grezPower_, grezPower_ + (sizeof(grezPower_) / sizeof(grezPower_[0])));
		int expected_ = 6;
        assertEquals(2, expected_, solution.maxWins(initialLevel, grezPower));
    }

    void testCase3() {
		int initialLevel = 4;
        int grezPower_[] = {3, 13, 6, 4, 9};
        vector<int> grezPower(grezPower_, grezPower_ + (sizeof(grezPower_) / sizeof(grezPower_[0])));
		int expected_ = 5;
        assertEquals(3, expected_, solution.maxWins(initialLevel, grezPower));
    }

    void testCase4() {
		int initialLevel = 7;
        int grezPower_[] = {7, 8, 9, 10};
        vector<int> grezPower(grezPower_, grezPower_ + (sizeof(grezPower_) / sizeof(grezPower_[0])));
		int expected_ = 0;
        assertEquals(4, expected_, solution.maxWins(initialLevel, grezPower));
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
        PrimalUnlicensedCreaturesTest test;
        test.runTest(i);
    }
}
