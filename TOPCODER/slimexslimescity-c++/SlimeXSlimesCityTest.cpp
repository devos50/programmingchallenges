#include "SlimeXSlimesCity.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SlimeXSlimesCityTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    SlimeXSlimesCity solution;

    void testCase0() {
        int population_[] = {2, 3, 4};
        vector<int> population(population_, population_ + (sizeof(population_) / sizeof(population_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.merge(population));
    }

    void testCase1() {
        int population_[] = {1, 2, 3};
        vector<int> population(population_, population_ + (sizeof(population_) / sizeof(population_[0])));
		int expected_ = 2;
        assertEquals(1, expected_, solution.merge(population));
    }

    void testCase2() {
        int population_[] = {8, 2, 3, 8};
        vector<int> population(population_, population_ + (sizeof(population_) / sizeof(population_[0])));
		int expected_ = 2;
        assertEquals(2, expected_, solution.merge(population));
    }

    void testCase3() {
        int population_[] = {1000000000, 999999999, 999999998, 999999997};
        vector<int> population(population_, population_ + (sizeof(population_) / sizeof(population_[0])));
		int expected_ = 3;
        assertEquals(3, expected_, solution.merge(population));
    }

    void testCase4() {
        int population_[] = {1, 1, 1};
        vector<int> population(population_, population_ + (sizeof(population_) / sizeof(population_[0])));
		int expected_ = 3;
        assertEquals(4, expected_, solution.merge(population));
    }

    void testCase5() {
        int population_[] = {1, 2, 4, 6, 14, 16, 20};
        vector<int> population(population_, population_ + (sizeof(population_) / sizeof(population_[0])));
		int expected_ = 3;
        assertEquals(5, expected_, solution.merge(population));
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
        SlimeXSlimesCityTest test;
        test.runTest(i);
    }
}
