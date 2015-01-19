#include <iostream>

using namespace std;

int n, m; // n = letters, m = word length

int rec(int cur, int last)
{
    if(cur == m - 1) return 1;
	
    if(cur == 0 || 2 * last > n)
    {
        // this letter can be anything
        int ans = 0;
        for(int i = 1; i <= n; i++) ans += rec(cur + 1, i);
        return ans;
    }
    else
    {
        // this letter can only be j iff j >= 2*i
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(i >= 2 * last) ans += rec(cur + 1, i);
        return ans;
    }
}

long long dp_ans()
{
	long long dp[m][n+1];
	
	// base case
	for(int i = 0; i <= n; i++) dp[m - 1][i] = 1;
	
	// fill
	for(int i = m - 2; i >= 0; i--)
	{
		for(int j = 0; j <= n; j++)
		{
			if(2 * j > n)
			{
				long long ans = 0;
				for(int k = 1; k <= n; k++) ans += dp[i + 1][k];
				dp[i][j] = (ans % 100000007);
			}
			else
			{
				long long ans = 0;
				for(int k = 1; k <= n; k++)
					if(k >= 2 * j) ans += dp[i + 1][k];
				dp[i][j] = (ans % 100000007);
			}
		}
	}
	/*
	for(int y = 0; y < m; y++)
	{
		for(int x = 0; x <= n; x++)
		{
			cout << dp[y][x] << " ";
		}
		cout << endl;
	}
	*/
	return dp[0][n];
}

void solve()
{
	cin >> n >> m;
	    
	 // int ans = rec(0, 0);
	 long long ans = dp_ans();
	 // multiply the answer with the possible ending letters
	 int posses = 0;
	 for(int i = 1; i <= n; i++)
	    if(2*i > n) posses++;
	 ans = (ans * posses) % 100000007;
	    
	 cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}