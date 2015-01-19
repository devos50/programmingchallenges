#include <iostream>
#include <cmath>

using namespace std;

long long coins[1005];
long long n;

void solve(int c)
{
	cin >> n;
	for(long long i = 0; i < n; i++) cin >> coins[i];
	
	long long dp[n+5]; for(long long i = 0; i < n+5; i++) dp[i] = 0;
	
	for(long long i = n-1; i >= 0; i--)
		dp[i] = max(coins[i] + dp[i + 2], dp[i + 1]);
	
	cout << "Case " << c << ": " << dp[0] << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	int c = 1;
	while(t--) { solve(c); c++; }
}