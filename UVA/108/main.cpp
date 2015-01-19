#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int size; cin >> size;
	int a[size][size];
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			cin >> a[i][j];
			
	// bereken sum array
	int dp[size][size];
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(i == 0 && j == 0)
			{
				dp[0][0] = a[0][0];
				continue;
			}
			if(i == 0)
			{
				dp[i][j] = dp[i][j-1] + a[i][j];
				continue;
			}
			if(j == 0)
			{
				dp[i][j] = dp[i-1][j] + a[i][j];
				continue;
			}
			dp[i][j] = a[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
		}
	}
	
	int maxsum = -100000000;
	for(int x1 = 0; x1 < size; x1++)
	{
		for(int x2 = x1; x2 < size; x2++)
		{
			for(int y1 = 0; y1 < size; y1++)
			{
				for(int y2 = y1; y2 < size; y2++)
				{
					int sum = 0;
					if(x1 == 0 && y1 == 0) sum = dp[y2][x2];
					else if(x1 == 0) sum = dp[y2][x2] - dp[y1-1][x2];
					else if(y1 == 0) sum = dp[y2][x2] - dp[y2][x1-1];
					else sum = dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1];
					if(sum > maxsum) maxsum = sum;
					// cout << "(" << x1 << "," << y1 << ") -> (" << x2 << "," << y2 << ")" << endl;
					// cout << "sum: " << sum << endl;
				}
			}
		}
	}
	cout << maxsum << endl;
}