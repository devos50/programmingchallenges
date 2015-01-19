#include <iostream>

#define MOD 1000000007

using namespace std;

long long modrest[50];
long long u, d, m, n;

long long powmod(long long b, long long e, long long p)
{
	long long res = 1;
	while(e > 0)
	{
		if(e % 2 == 1) res = (res * b) % p;
		e >>= 1;
		b = (b * b) % p;
	}
	return res;
}

long long solutions(int e) // number of solutions to a^d % n = e
{
	long long freq = 0;
	
	if(u < n)
	{
		for(int i = 0; i <= u; i++)
			if(modrest[i] == e) freq++;
		return freq;
	}
	
	for(int i = 0; i < n; i++)
		if(modrest[i] == e) freq++;
	
	long long times = u / n;
	if(times > 0) freq *= (u / n);
	
	for(long long i = times * n; i <= u; i++)
	{
		if(modrest[i % n] == e) freq++;
	}
	
	// cout << "solutions(" << e << ") = " << freq % MOD << endl;
	return freq % MOD;
}

void solve()
{
	cin >> u >> d >> m >> n;
	
	if(d == 0 && m == 0 && n == 1)
	{
		// solutions = (a + 1) * (b + 1) * (c + 1)
		long long sols = ((u + 1) * (u + 1)) % MOD;
		sols *= (u + 1);
		sols %= MOD;
		cout << sols << endl;
		
		return;
	}
	
	// calculate the modrests
	for(int i = 0; i < n; i++)
	{
		modrest[i] = powmod(i, d, n);
		// cout << "MODREST: " << modrest[i] << endl;
	}
	
	// cout << "s: " << solutions(0);
	
	long long ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
			{
				if((i + j + k) % n == m)
				{
					long long s_i = solutions(i);
					long long s_j = solutions(j);
					long long s_k = solutions(k);
					
					long long f = (s_i * s_j) % MOD;
					f = (f * s_k) % MOD;
					
					ans += f;
					ans %= MOD;
					
					// cout << i << " " << j << " " << k << ", s_i: " << s_i << ", s_j: " << s_j << ", s_k: " << s_k << endl;
				}
			}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}