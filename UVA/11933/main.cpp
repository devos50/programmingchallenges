#include <iostream>

using namespace std;

void solve(long long n)
{
	long long one = 1;
	long long cur = 0;
	long long a = 0;
	long long b = 0;
	bool inA = true;
	while(true)
	{
		// cout << "cur: " << (one << cur) << endl;
		if(one << cur > n) break;
		
		// get bit at position cur
		long long bit = n & (one << cur);
		// cout << "bit at position " << cur << ": " << (bit) ? 1 : 0;
		// cout << endl;
		if(bit)
		{
			if(inA) a |= one << cur;
			else b |= one << cur;
			inA = !inA;
		}
		cur++;
	}
	cout << a << " " << b << endl;
}

int main(int argc, char *argv[]) 
{
	long long n;
	while(true)
	{
		cin >> n;
		if(!n) break;
		solve(n);
	}
}