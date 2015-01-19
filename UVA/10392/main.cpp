#include <iostream>
#include <vector>

#define LL long long int
#define MAX 1000001

using namespace std;

vector<int> primes;

void solve(LL n)
{
	vector<LL> divs;
	bool can = true;
	while(can)
	{
		bool found = false;
		for(vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
		{
			if(n % *it == 0)
			{
				// cout << "n: " << n << endl;
				found = true;
				divs.push_back(*it);
				n /= *it;
				break;
			}
		}
		
		if(!found)
		{
			can = false;
			if(n != 1) divs.push_back(n);
		}
	}
	
	for(vector<LL>::iterator it = divs.begin(); it != divs.end(); it++)
	{
		cout << "    " << *it << endl;
	}
	cout << endl;
}

bool isPrime(int n)
{
	if(n == 2) return true;
	if(n == 0 || n == 1 || n % 2 == 0) return false;
	for(int i = 3; i * i <= n; i+=2)
		if(n % i == 0) return false;
	return true;
}

void calcPrimes()
{
	for(int i = 2; i < MAX; i++)
	{
		if(isPrime(i)) primes.push_back(i);
	}
}

int main(int argc, char *argv[]) 
{
	LL n;
	calcPrimes();
	while(true)
	{
		cin >> n;
		if(n == -1) break;
		
		solve(n);
	}
}