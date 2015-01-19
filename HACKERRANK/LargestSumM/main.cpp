#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int n, k, m;
vector<int> nums;

void count(int target, vector<long long> coins)
{
	long long out[target]; for(int i = 0; i < target; i++) out[i] = 0;
	
	for (int a = 0; a < coins.size(); a++)
	{
		for (int b = coins[a] - 1; b < target; b++)
	    {
	     	if (b - coins[a] == -1) out[b] += 1;
	        else
            {
                out[b] += out[b - coins[a]];
                out[b] %= 1000000007;
            }
	    }
	}
	cout << out[target - 1] << endl;
}

int solvedp()
{
	// tabel verkleinen!
	bool dp1[n][m], dp2[n][m];
	// bool dp[n][m][k+1];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			dp1[i][j] = false;
			dp2[i][j] = false;
		}
	
	for(int el = 0; el < n; el++)
		for(int i = 0; i <= el; i++)
		{
			dp1[el][nums[i]] = true;
		}
			
	
	for(int l = 2; l <= k; l++)
	{
		// clear dp2
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				dp2[i][j] = false;
		
		for(int m1 = 1; m1 < m; m1++)
		{
			for(int i = 0; i < n-1; i++)
			{
				if(m1 - nums[i+1] < 0) dp2[i+1][m1] = dp2[i][m1];
				else dp2[i+1][m1] = dp2[i][m1] || dp1[i][m1 - nums[i+1]];
			}
		}
		
		// copy dp2 to dp1
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				dp1[i][j] = dp2[i][j];
	}
	
	int max = -1;
	for(int i = m-1; i > 0; i--)
		if(dp1[n-1][i] && i > max) { max = i; break; }
	
	return max;
}

int main(int argc, char *argv[]) 
{
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++)
	{
		int num; cin >> num;
		nums.push_back(num);
	}
	
	// task 1: find largest sum
	int ans1 = solvedp();
	cout << ans1 << endl;
	
	// task 2: calculate partitions
	vector<long long> coins;
	for(int i = 1; i <= ans1; i++) coins.push_back(i);
	
	count(ans1, coins);
}