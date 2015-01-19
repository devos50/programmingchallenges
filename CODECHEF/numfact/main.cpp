#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

bool isPrime[1000005];
vector<int> primes;
map<int, int> factors;

void sieve()
{
	for(int i = 0; i < 1000005; i++) isPrime[i] = true;
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2; i < 1000000; i++)
	{
		if(isPrime[i])
		{
			for(int k = 2 * i; k < 1000000; k += i)
				isPrime[k] = false;
		}
	}
	
	for(int i = 0; i < 1000000; i++)
		if(isPrime[i]) primes.push_back(i);
}

void factor(int n)
{
	int cur = n;
	// cout << "n: " << n << endl;
	for(int i = 0; i < primes.size(); i++)
	{
		while(cur % primes[i] == 0) // while we can divide cur by primes[i]
		{
			cur /= primes[i];
			
			if(factors.find(primes[i]) == factors.end()) factors[primes[i]] = 1;
			else factors[primes[i]]++;
			
			// cout << "factor: " << primes[i] << endl;
			if(cur == 1) break;
		}
		if(cur == 1) break;
	}
}

void solve()
{
	factors.clear();
	int n; cin >> n;
	
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		int k; cin >> k;
		factor(k);
	}
	
	int divs = 1;
	for(map<int, int>::iterator it = factors.begin(); it != factors.end(); it++)
	{
		divs *= (it->second + 1);
	}
	
	cout << divs << endl;
}

int main(int argc, char *argv[]) 
{
	sieve();
	
	int t; cin >> t;
	while(t--) solve();
}