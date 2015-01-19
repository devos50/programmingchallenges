/*
 ID: mdmarti1
 PROG: nocows
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int dp[205][105];

int main()
{
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    int n, k;
    fin >> n >> k;

	// fill memo
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
			dp[i][j] = 0;
	
	
	for(int curk = 1; curk <= k; curk++)
	{
		for(int curn = 1; curn <= n; curn++)
		{
			if(curn == 1 && curk == 1) { dp[curn][curk] = 1; continue; }
			else if(curk == 1 && curn > 0) { dp[curn][curk] = 0; continue; }
			else if(curn % 2 == 0) { dp[curn][curk] = 0; continue; }
			int res = 0;
			for(int nLeft = 1; nLeft < curn - 1; nLeft++)
			{
				int nRight = curn - nLeft - 1;
				for(int kLeft = 1; kLeft < curk - 1; kLeft++)
				{
					int ansLeft = dp[nLeft][kLeft];
					int ansRight = dp[nRight][curk - 1];
					res += ansLeft * ansRight;
					res %= 9901;
				}
					
				// apart geval als kLeft == k
				for(int kRight = 1; kRight < curk; kRight++)
				{
					int ansRight = dp[nRight][kRight];
					int ansLeft = dp[nLeft][curk - 1];
					res += ansLeft * ansRight;
					res %= 9901;
				}
			}
			// cout << "cur n: " << curn << ", curk: " << curk << ": " << res << endl;
 			dp[curn][curk] = res;
		}
	}
	fout << dp[n][k] << endl;
	
    return 0;
}
