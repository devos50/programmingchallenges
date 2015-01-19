#include <iostream>

using namespace std;

long long powermod(long long b, long long e, long long m)
{
	long long res = 1;
	while(e > 0)
	{
		if(e % 2 == 1) res = (res * b) % m;
		e >>= 1;
		b = (b * b) % m;
	}
	return res;
}

void solve()
{
	long long n; cin >> n;
	long long ans = powermod(2, n, 1000000007);
	ans--;
	
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}