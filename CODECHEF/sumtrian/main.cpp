#include <cstdio>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

void solve()
{
	int tree[1005][1005];
	int r; scanf("%d", &r);
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < i + 1; j++)
		{
			scanf("%d", &tree[i][j]);
			// cin >> tree[i][j];
		}
	}
	int dp[1005][1005];
	dp[0][0] = tree[0][0];
	for(int i = 1; i < r; i++)
	{
		for(int j = 0; j < i+1; j++)
		{
			if(j == 0) dp[i][j] = tree[i][j] + dp[i-1][j];
			else dp[i][j] = tree[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
		}
	}
	
	int ans = INT_MIN;
	for(int i = 0; i < r; i++) { ans = max(ans, dp[r - 1][i]); }

	printf("%d\n", ans);
}

int main()
{
	int t; scanf("%d", &t);
	while(t--) solve();
}