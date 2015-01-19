#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

void solve(int n)
{
	long long g = 0;
	for(long long i = 1; i < n; i++)
	{
		for(long long j = i + 1; j <= n; j++)
		{
			g += gcd(i,j);
		}
	}
	cout << g << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}
}