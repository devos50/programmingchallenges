#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

int main(int argc, char *argv[]) 
{
	fstream f; f.open("triangle.txt");
	int tree[100][100];
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < i+1; j++)
		{
			f >> tree[i][j];
			// cout << "num: " << tree[i][j] << endl;
		}
	}
	
	int dp[100][100];
	dp[0][0] = tree[0][0];
	for(int i = 1; i < 100; i++)
	{
		for(int j = 0; j < i+1; j++)
		{
			if(j == 0) dp[i][j] = tree[i][j] + dp[i-1][j];
			else dp[i][j] = tree[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
		}
	}
	
	int ans = INT_MIN;
	for(int i = 0; i < 100; i++) ans = max(ans, dp[99][i]);
	cout << ans;
}