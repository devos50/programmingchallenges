#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

using namespace std;

int divsum[1000005];
bool is_prime[1000005];

void sieve()
{
	int n = 1000003;
	for(int i = 2; i < n; i++) is_prime[i] = true;
	is_prime[0] = false;
	is_prime[1] = false;
	
	for(int i = 2; i * i < n; i++)
	{
		if(is_prime[i])
			for(int j = i * i; j < n; j += i)
				is_prime[j] = false;
	}
}

long long div_sum(long long n)
{
	if(is_prime[n]) return 1;

	long long sum = 1;
	long long k = n;	
	for(long long i = 2; i < 1000; i++)
	{
		long long s = 1;
		while(k % i == 0)
		{
			k /= i;
			s *= i;
			// cout << i << endl;
		}
		
		sum *= (s * i - 1) / (i - 1 );
		
		// if the remainder is a prime, return
		if(is_prime[k])
		{
			// cout << ((k * k - 1) / ( k - 1)) << endl;
			return sum * ((k * k - 1) / ( k - 1)) - n;
		}
	}
}

int main(int argc, char *argv[])
{
	sieve();
	
	for(int i = 2; i <= 1000000; i++) divsum[i] = div_sum(i);
	divsum[0] = 0;
	divsum[1] = 0;
	
	int maxlen = -1;
	int maxnum = -1;
	for(int k = 1; k <= 1000000; k++)
	{
		k = 979828;
		if(k % 10000 == 0) cout << "k: " << k << endl;
		int n = k;
		cout << "n: " << n << endl;
		set<int> seen; seen.insert(n);
		int length = 1;
		bool undermil = true;
	
		while(seen.find(divsum[n]) == seen.end())
		{
			seen.insert(divsum[n]);
			n = divsum[n];
			if(n > 1000000) { undermil = false; break; }
			
			length++;
			cout << n << endl;
		}	
	
		if(undermil && n != 0)
		{
			if(length > maxlen) { maxlen = length; maxnum = k; }
		}
		break;
	}
	cout << maxnum << " => " << maxlen << endl;
}