#include "SpaceWarDiv2.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SpaceWarDiv2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    SpaceWarDiv2 solution;

    void testCase0() {
        int magicalGirlStrength_[] = {2, 3, 5};
        vector<int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_ + (sizeof(magicalGirlStrength_) / sizeof(magicalGirlStrength_[0])));
        int enemyStrength_[] = {1, 3, 4};
        vector<int> enemyStrength(enemyStrength_, enemyStrength_ + (sizeof(enemyStrength_) / sizeof(enemyStrength_[0])));
        int enemyCount_[] = {2, 9, 4};
        vector<int> enemyCount(enemyCount_, enemyCount_ + (sizeof(enemyCount_) / sizeof(enemyCount_[0])));
		int expected_ = 7;
        assertEquals(0, expected_, solution.minimalFatigue(magicalGirlStrength, enemyStrength, enemyCount));
    }

    void testCase1() {
        int magicalGirlStrength_[] = {2, 3, 5};
        vector<int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_ + (sizeof(magicalGirlStrength_) / sizeof(magicalGirlStrength_[0])));
        int enemyStrength_[] = {1, 1, 2};
        vector<int> enemyStrength(enemyStrength_, enemyStrength_ + (sizeof(enemyStrength_) / sizeof(enemyStrength_[0])));
        int enemyCount_[] = {2, 9, 4};
        vector<int> enemyCount(enemyCount_, enemyCount_ + (sizeof(enemyCount_) / sizeof(enemyCount_[0])));
		int expected_ = 5;
        assertEquals(1, expected_, solution.minimalFatigue(magicalGirlStrength, enemyStrength, enemyCount));
    }

    void testCase2() {
        int magicalGirlStrength_[] = {14, 6, 22};
        vector<int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_ + (sizeof(magicalGirlStrength_) / sizeof(magicalGirlStrength_[0])));
        int enemyStrength_[] = {8, 33};
        vector<int> enemyStrength(enemyStrength_, enemyStrength_ + (sizeof(enemyStrength_) / sizeof(enemyStrength_[0])));
        int enemyCount_[] = {9, 1};
        vector<int> enemyCount(enemyCount_, enemyCount_ + (sizeof(enemyCount_) / sizeof(enemyCount_[0])));
		int expected_ = -1;
        assertEquals(2, expected_, solution.minimalFatigue(magicalGirlStrength, enemyStrength, enemyCount));
    }

    void testCase3() {
        int magicalGirlStrength_[] = {17, 10, 29, 48, 92, 60, 80, 100, 15, 69, 36, 43, 70, 14, 88, 12, 14, 29, 9, 40};
        vector<int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_ + (sizeof(magicalGirlStrength_) / sizeof(magicalGirlStrength_[0])));
        int enemyStrength_[] = {93, 59, 27, 68, 48, 82, 15, 95, 61, 49, 68, 15, 16, 26, 64, 82, 7, 8, 92, 15};
        vector<int> enemyStrength(enemyStrength_, enemyStrength_ + (sizeof(enemyStrength_) / sizeof(enemyStrength_[0])));
        int enemyCount_[] = {56, 26, 12, 52, 5, 19, 93, 36, 69, 61, 68, 66, 55, 28, 49, 55, 63, 57, 33, 45};
        vector<int> enemyCount(enemyCount_, enemyCount_ + (sizeof(enemyCount_) / sizeof(enemyCount_[0])));
		int expected_ = 92;
        assertEquals(3, expected_, solution.minimalFatigue(magicalGirlStrength, enemyStrength, enemyCount));
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
        SpaceWarDiv2Test test;
        test.runTest(i);
    }
}
