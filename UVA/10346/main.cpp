#include <iostream>

using namespace std;

void solve(long n, long k)
{
	int ans = n / c;
	int b = n;
	while(b / k > 0)
	{
		ans = ans + b / k;
		b = (b / k) + b % k;
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	long n, k;
	while(cin >> n >> k) solve(n, k);
}