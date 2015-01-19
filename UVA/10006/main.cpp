#include <iostream>

using namespace std;

bool is_carmichael[65005];

long long numbers[] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973 };

bool is_prime(int n)
{
	if(n == 0 || n == 1) return false;
	else if(n == 2) return true;
	else if(n % 2 == 0) return false;
	
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0) return false;
	return true;
}

long long powmod(long long b, long long e, long long m)
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

void precalculate()
{
	for(int i = 0; i < 65005; i++) is_carmichael[i] = false;
	
	for(int n = 3; n < 65000; n++)
	{
		bool is_car = true;
		for(long long i = 2; i < n; i++)
		{
			if(powmod(i, n, n) != i)
			{
				// cout << "i: " << i << ", n: " << n << endl;
				is_car = false;
				break;
			}
		}
		if(!is_prime(n) && is_car) { is_carmichael[n] = true; cout << "num: " << n << endl; }
	}
}

void solve(long long n)
{
	bool found = false;
	for(int i = 0; i < 15; i++)
	{
		if(numbers[i] == n) found = true;
	}
	if(found) cout << "The number " << n << " is a Carmichael number." << endl;
	else cout << n << " is normal." << endl;
}

int main(int argc, char *argv[]) 
{
	// for(int i = 0; i < 17; i++) cout << powmod(i, 17, 17) << endl;
	// precalculate();
	
	long long n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}
}