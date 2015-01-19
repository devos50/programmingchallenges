#include <iostream>

using namespace std;

int n;
double p[105];
int f[105];

double rec(int level, int b_flags)
{
	if(b_flags < 0) return 0.0;
	
	if(level == 0)
	{
		if(f[level] == b_flags) return p[level];
		else if(b_flags == 0) return 1.0 - p[level];
		else return 0.0;
	}
	
	return p[level] * rec(level - 1, b_flags - f[level]) + (1 - p[level]) * rec(level - 1, b_flags);
}

void solve()
{
	cin >> n;
	int total_flags = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> f[i];
		total_flags += f[i];
	}
		
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i] /= 100.0;
	}
	
	// fill dp table
	double dp[n][total_flags+3];
	for(int level = 0; level < n; level++)
	{
		for(int b_flags = 0; b_flags <= total_flags; b_flags++)
		{
			if(level == 0)
			{
				if(f[level] == b_flags) dp[level][b_flags] = p[level];
				else if(b_flags == 0) dp[level][b_flags] = 1.0 - p[level];
				else dp[level][b_flags] = 0.0;
			}
			else if(b_flags - f[level] < 0) dp[level][b_flags] = (1 - p[level]) * dp[level - 1][b_flags];
			else dp[level][b_flags] = p[level] * dp[level - 1][b_flags - f[level]] + (1 - p[level]) * dp[level - 1][b_flags];
		}
	}
	
	// calculate using rec
	
	double ans = 0;
	int needed_flags = total_flags / 2;
	if(total_flags % 2 == 1) needed_flags++;
	/*
	for(int i = needed_flags; i <= total_flags; i++)
		ans += rec(n - 1, i);
	cout << ans << endl;
	*/
	ans = 0;
	for(int i = needed_flags; i <= total_flags; i++)
		ans += dp[n - 1][i];
		
	cout.precision(8);
	cout << fixed << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}