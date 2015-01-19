#include <iostream>
#include <map>

#define MOD 1000000009

using namespace std;

long long find_k(long long n, long long p)
{
	long long ans = 0;
	while(n != 0)
	{
		ans += n / p;
		n /= p;
	}
	return ans;
}

void prime_factor(long long n)
{
	long long a = 1, b = n;
	    
	bool *primes = new bool[b-a+1];
	for(long long i = 0; i < b - a + 1; i++)
		primes[i] = false;
	    
	for(long long p = 2; p * p <= b; p++)
	{
	   long long less = a / p;
	   less *= p;
	       
	   for(long long j = less; j <= b; j += p) 
			if(j != p && j >= a)
	       		primes[j - a] = true;
	}
	
	long long ans = 1;
	
	for(long long i = 0; i < b - a + 1; i++)
	{
		if(primes[i] == false && a+i != 1)
		{
			long long p = a + i;
			long long k = find_k(n, p) * 2;
			// cout << "factor: " << p << "^" << k << endl;
			
			long long mod = 1;
			for(int i = 0; i < k; i++)
			{
				mod *= p;
				mod %= MOD;
			}
			mod++;
			mod %= MOD;
			
			ans *= mod;
			ans %= MOD;
		}
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	prime_factor(100000000);
}