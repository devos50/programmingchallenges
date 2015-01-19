#include <iostream>

using namespace std;

long long digsum(long long n)
{
	long long sum = 0;
	while(n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void solve(long long n)
{
	while(n / 10 != 0)
	{
		long long sum = digsum(n);
		//  cout << "sum: " << sum << endl;
		n = sum;
	}
	cout << n << endl;
}

int main(int argc, char *argv[]) 
{
	long long n;
	cin >> n;
	while(n != 0) 
	{
		solve(n);
		cin >> n;
	}
}