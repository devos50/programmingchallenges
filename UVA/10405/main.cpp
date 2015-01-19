#include <iostream>
#include <cmath>

using namespace std;

void solve(string s1, string s2)
{
	int m = s1.size(), n = s2.size();
	int dp[m+1][n+1];
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(s1.at(i-1) == s2.at(j-1))
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[m][n] << endl;
}

int main(int argc, char *argv[]) 
{
	string s1, s2;
	while(getline(cin, s1) && getline(cin, s2))
		solve(s1, s2);
}