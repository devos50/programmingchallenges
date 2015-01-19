#include "MarblePositioning.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class MarblePositioningTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    MarblePositioning solution;

    void testCase0() {
        int radius_[] = {1, 2};
        vector<int> radius(radius_, radius_ + (sizeof(radius_) / sizeof(radius_[0])));
		double expected_ = 2.8284271247461903;
        assertEquals(0, expected_, solution.totalWidth(radius));
    }

    void testCase1() {
        int radius_[] = {7, 7, 7};
        vector<int> radius(radius_, radius_ + (sizeof(radius_) / sizeof(radius_[0])));
		double expected_ = 28.0;
        assertEquals(1, expected_, solution.totalWidth(radius));
    }

    void testCase2() {
        int radius_[] = {10, 20, 30};
        vector<int> radius(radius_, radius_ + (sizeof(radius_) / sizeof(radius_[0])));
		double expected_ = 62.92528739883945;
        assertEquals(2, expected_, solution.totalWidth(radius));
    }

    void testCase3() {
        int radius_[] = {100, 100, 11, 11, 25};
        vector<int> radius(radius_, radius_ + (sizeof(radius_) / sizeof(radius_[0])));
		double expected_ = 200.0;
        assertEquals(3, expected_, solution.totalWidth(radius));
    }

    void testCase4() {
        int radius_[] = {1, 999950884, 1};
        vector<int> radius(radius_, radius_ + (sizeof(radius_) / sizeof(radius_[0])));
		double expected_ = 63246.0;
        assertEquals(4, expected_, solution.totalWidth(radius));
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
        MarblePositioningTest test;
        test.runTest(i);
    }
}
