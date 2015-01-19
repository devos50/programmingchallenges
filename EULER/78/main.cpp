#include <iostream>

using namespace std;

int memo[100000];

long long p(int n)
{
	if(n == 1) return 1;
	if(n == 0) return 1;
	if(n < 0) return 0;
	
	if(memo[n] != -1) return memo[n];
	
	long long ans = 0;
	bool neg = false;
	for(int k = 1; k <= n; k++)
	{
		long long toadd = p(n - 0.5 * k * (3 * k - 1)) + p(n - 0.5 * k * (3 * k + 1));
		if(neg) toadd *= -1;
		ans += toadd;
		neg = !neg;
		
		ans %= 1000000;
	}
	
	memo[n] = ans;
	return ans;
}

int main(int argc, char *argv[]) 
{
	for(int i = 0; i < 100000; i++) memo[i] = -1;
	
	int cur = 5;
	while(true)
	{
		if(cur % 1000 == 0) cout << cur << endl;
		
		int ans = p(cur);
		if(ans % 1000000 == 0)
		{
			cout << cur << endl;
			break;
		}
		cur++;
	}
}