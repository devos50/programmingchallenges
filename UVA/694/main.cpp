#include <iostream>

using namespace std;

void solve(long long a, long long l, int c)
{
	long long cur = a;
	int steps = 1;
	while(true)
	{
		if(cur > l) steps--;
		if(cur == 1 || cur > l) { cout << "Case " << c << ": A = " << a << ", limit = " << l << ", number of terms = " << steps << endl; break; }
		if(cur % 2 == 0) cur /= 2;
		else cur = 3 * cur + 1;
		steps++;
	}
}

int main(int argc, char *argv[]) 
{
	long long a, l;
	int c = 1;
	while(true)
	{
		cin >> a >> l;
		if(a < 0 && l < 0) break;
		solve(a, l, c);
		c++;
	}
}