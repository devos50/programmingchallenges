#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class MatrixShiftings {

	public: int minimumShifts(vector<string> matrix, int value) {

		int N = matrix.size(); int M = matrix[0].size();
		int minmoves = 100000;
		for(int y = 0; y < N; y++)
		{
			for(int x = 0; x < M; x++)
			{
				if(matrix[y][x] == '0' + value)
				{
					cout << "val: " << matrix[y][x] << endl;
					// boven of beneden?
					int vertical = min(y, N - y);
					int horizontal = min(x, M - x);
					cout << "vert: " << vertical << ", hor: " << horizontal << endl;
					if(vertical + horizontal < minmoves)
						minmoves = vertical + horizontal;
				}
			}
		}

		if(minmoves == 100000) return -1;
		return minmoves;
	}

};
