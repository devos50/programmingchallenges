#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > pairs;
bool primes[35000];

bool containsPair(int a, int b)
{
	for(vector<pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if((a == it->first && b == it->second) || (a == it->second && b == it->first)) return true;
	}
	return false;
}

void solve(int n)
{
	int count = 0;
	for(int i = 1; i < n; i++)
	{
		int a = i, b = n - i;
		if(primes[a] && primes[b] && !containsPair(a, b)) 
		{
			pairs.push_back(make_pair(a, b));
			count++;
		}
	}
	cout << count << endl;
}

bool isPrime(int n)
{
	if(n == 2) return true;
	if(n == 0 || n == 1 || n % 2 == 0) return false;
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0) return false;
	return true;
}

int main(int argc, char *argv[]) 
{
	// prepare primes
	for(int i = 0; i < 35000; i++) primes[i] = isPrime(i);
	
	while(true)
	{
		int n; cin >> n;
		if(n == 0) break;
		pairs.clear();
		solve(n);
	}
}