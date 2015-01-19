#include <iostream>
#include <vector>

using namespace std;

bool primes[1000005];

bool isPrime(int n)
{
	if(n == 0 || n == 1 || n % 2 == 0) return false;
	for(int i = 3; i*i <= n; i+=2)
		if(n % i == 0) return false;
	return true;
}

void solve(int n)
{	
	for(int i = 1; i < n; i++)
		if(primes[i] && primes[n - i])
		{
			cout << n << " = " << i << " + " << n - i << endl;
			return;
		}
		
	cout << "Goldbach's conjecture is wrong." << endl;
}

int main(int argc, char *argv[]) 
{
	for(int i = 1; i < 1000005; i++) primes[i] = isPrime(i);
	
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}
}