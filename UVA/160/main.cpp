#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;

bool isPrime(int n)
{
	if(n == 1 || n == 2) return true;
	if(n == 0 || n % 2 == 0) return false;
	for(int i = 3; i * i <= n; i+=2)
		if(n % i == 0) return false;
	return true;
}

void solve(int n)
{
	int dp[105];
	for(int i = 1; i <= n; i++) dp[i] = i;
	
	int divs[105]; for(int i = 0; i < 101; i++) divs[i] = 0;
	for(vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		int prime = *it;
		for(int i = 1; i <= n; i++)
		{
			while(dp[i] % prime == 0)
			{
				dp[i] /= prime;
				divs[prime]++;
			}
		}
	}
	
	// print output
	if(n < 10) cout << "  ";
	else if(n < 100) cout << " ";
	cout << n << "! =";
	
	// iterate over the rows
	int counter = 0;
	for(vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		if(divs[*it] == 0) break;
		counter++;
	}
	
	int rows = counter / 15 + 1;
	if(counter == 15) rows = 1;
	
	for(int row = 0; row < rows; row++)
	{
		for(int i = 0; i < 15; i++)
		{
			int prime = primes[row * 15 + i];
			if(divs[prime] == 0) break;
			if(divs[prime] < 10) cout << "  " << divs[prime];
			else cout << " " << divs[prime];
		}
		if(row != rows - 1) cout << endl << "      ";
	}
	/*
	for(vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		int prime = *it;
		if(divs[prime] == 0) break;
		if(divs[prime] < 10) cout << "  " << divs[prime];
		else cout << " " << divs[prime];
	}
	*/
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	for(int i = 2; i <= 100; i++)
			if(isPrime(i)) primes.push_back(i);
			
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}
}