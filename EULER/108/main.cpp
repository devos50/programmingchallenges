#include <iostream>

using namespace std;

long long divs(long long n)
{
	long long ans = 0;
	for(long long i = 1; i <= n; i++)
	{
		if((n * n) % i == 0) ans++;
	}
	return ans;
}

int main(int argc, char *argv[]) 
{
	long long max = 0;
	long long cur = 0;
	while(true)
	{
		long long d = divs(cur);
		if(d > max)
		{
			max = d;
			cout << "new max: " << max << ", n: " << cur << endl;
		}
		// cout << "n: " << cur << ": " << d << endl;
		if(d > 1000)
		{
			cout << cur << endl;
			return 0;
		}
		cur++;
	}
}