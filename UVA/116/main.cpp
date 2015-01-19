
// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct cell {
    int val;
    int child;
} matrix [15] [103];
int row, col;

void reset()
{
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            matrix[i][j].child = -1;
    }
}

int main()
{
    while(cin >> row >> col) 
	{
        reset();

        for(int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) 
				cin >> matrix[i][j].val;

        for(int j = col - 2; j >= 0; j--) 
		{
            for(int i = 0; i < row; i++) 
			{
                int thisNum = matrix[i][j].val;

                matrix[i][j].val = thisNum + matrix[(row + i - 1) % row][j + 1].val;
                matrix[i][j].child = (row + i - 1) % row;

                int sum = thisNum + matrix [i] [j + 1].val;
                if(sum < matrix [i] [j].val) 
				{
                    matrix [i] [j].val = sum;
                    matrix [i] [j].child = i;
                }
                else if(sum == matrix [i] [j].val && matrix [i] [j].child > i) matrix [i] [j].child = i;

                sum = thisNum + matrix [(row + i + 1) % row] [j + 1].val;
                if (sum < matrix [i] [j].val) 
				{
                    matrix[i][j].val = sum;
                    matrix[i][j].child = (row + i + 1) % row;
                }
                else if (sum == matrix [i] [j].val && matrix [i] [j].child > (row + i + 1) % row) matrix[i][j].child = (row + i + 1) % row;
            }
        }

        int lowest = INT_MAX;
        int lowest_row;

        for(int i = 0; i < row; i++) 
		{
            if(matrix[i][0].val < lowest) 
			{
                lowest = matrix [i] [0].val;
                lowest_row = i;
            }
        }

        vector <int> path;

        for(int i = 0; i < col; i++)
		{
            path.push_back(lowest_row + 1);
            lowest_row = matrix[lowest_row][i].child;
        }

        bool space = false;
        for(int i = 0; i < path.size(); i++) 
		{
            if(space) cout << " ";
            space = true;
            cout << path[i];
        }
        cout << endl;
        cout << lowest << endl;
    }
}