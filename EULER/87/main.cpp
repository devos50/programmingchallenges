#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<long long> primes;
set<long long> numbers;

bool isPrime(long long n)
{
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0) return false;
	return true;
}

int main(int argc, char *argv[]) 
{
	for(long long i = 2; i <= 7100; i++)
		if(isPrime(i)) primes.push_back(i);
	cout << "primes: " << primes.size() << endl;
	
	for(int a = 0; a < primes.size(); a++)
	{
		cout << "a: " << a << endl;
		for(int b = 0; b < primes.size(); b++)
			for(int c = 0; c < primes.size(); c++)
			{
				long long n = primes[a] * primes[a] + primes[b] * primes[b] * primes[b] + primes[c] * primes[c] * primes[c] * primes[c];
				// cout << "n: " << n << endl;
				if(n < 50000000) numbers.insert(n);
				
			}
	}
	
	cout << numbers.size() << endl;
	
}