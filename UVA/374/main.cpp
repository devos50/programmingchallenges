#include <iostream>
#include <cmath>

using namespace std;

void solve(long b, long p, long m)
{
	long result = 1;
	while(p > 0)
	{
		if((p % 2) == 1)
		{
			result = (result * b) % m;
		}
		b = (b * b) % m;
		p = floor(p / 2);
	}
	cout << result << endl;
}

int main(int argc, char *argv[]) 
{
	long b, p, m;
	while(cin >> b >> p >> m) solve(b, p, m);
}