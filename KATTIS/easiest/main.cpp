#include <iostream>

using namespace std;

long long dsum(long long n)
{
	int sum = 0;
	while(n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void solve(long long n)
{
 	long long p = 11;
	long long nsum = dsum(n);
	while(dsum(n * p) != nsum)
	{
		p++;
	}
	cout << p << endl;
}

int main(int argc, char *argv[]) 
{
	long long n; cin >> n;
	while(n != 0)
	{
		solve(n);
		cin >> n;
	}
}