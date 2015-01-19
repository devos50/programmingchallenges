#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int dp[10005];
	dp[1] = 1;
	for(int cur = 2; cur <= n; cur++)
	{
		int posses = 0;
		for(int i = 1; i * i <= cur; i++)
		{
			if(cur % i == 0) posses++;
		}
		dp[cur] = dp[cur - 1] + posses;
	}
	cout << dp[n] << endl;
}