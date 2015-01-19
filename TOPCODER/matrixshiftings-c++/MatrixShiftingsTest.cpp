#include "MatrixShiftings.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class MatrixShiftingsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    MatrixShiftings solution;

    void testCase0() {
        string matrix_[] = {"136", "427", "568", "309"};
        vector<string> matrix(matrix_, matrix_ + (sizeof(matrix_) / sizeof(matrix_[0])));
		int value = 2;
		int expected_ = 2;
        assertEquals(0, expected_, solution.minimumShifts(matrix, value));
    }

    void testCase1() {
        string matrix_[] = {"0000", "0000", "0099"};
        vector<string> matrix(matrix_, matrix_ + (sizeof(matrix_) / sizeof(matrix_[0])));
		int value = 9;
		int expected_ = 2;
        assertEquals(1, expected_, solution.minimumShifts(matrix, value));
    }

    void testCase2() {
        string matrix_[] = {"0123456789"};
        vector<string> matrix(matrix_, matrix_ + (sizeof(matrix_) / sizeof(matrix_[0])));
		int value = 7;
		int expected_ = 3;
        assertEquals(2, expected_, solution.minimumShifts(matrix, value));
    }

    void testCase3() {
        string matrix_[] = {"555", "555"};
        vector<string> matrix(matrix_, matrix_ + (sizeof(matrix_) / sizeof(matrix_[0])));
		int value = 1;
		int expected_ = -1;
        assertEquals(3, expected_, solution.minimumShifts(matrix, value));
    }

    void testCase4() {
        string matrix_[] = {"12417727123", "65125691886", "55524912622", "12261288888"};
        vector<string> matrix(matrix_, matrix_ + (sizeof(matrix_) / sizeof(matrix_[0])));
		int value = 9;
		int expected_ = 6;
        assertEquals(4, expected_, solution.minimumShifts(matrix, value));
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
        MatrixShiftingsTest test;
        test.runTest(i);
    }
}
