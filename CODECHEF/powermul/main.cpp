#include <iostream>

using namespace std;

long long powerMod(long long b, long long e, long long m)
{
	long long res = 1;
	while(e > 0)
	{
		if(e % 2 == 1) { res = (res * b) % m; }
		e >>= 1;
		b = (b * b) % m;
	}
	return res;
}

void solve()
{
	long long n, m, q; cin >> n >> m >> q;
	
	// calculate each f(n)
	int f[n+5];
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		f[i] = (f[i - 1] * powerMod(i, i, m)) % m;
		cout << "f[" << i << "] = " << f[i] << endl;
	}
	
	for(int i = 0; i < q; i++)
	{
		long long r; cin >> r;
		long long num = f[n] % m;
		long long denum = (f[r] * f[n - r]) % m;
		cout << "num: " << f[n] << ", denum: " << (f[r] * f[n - r]) << endl;
		cout << (num / denum) % m << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}