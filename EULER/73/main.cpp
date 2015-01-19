#include <iostream>
#include <algorithm>
#include <vector>

#define D 1000000

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[]) 
{
	int ans = 0;
	for(int denum = 2; denum <= 12000; denum++)
	{
		for(int i = 1; i < denum; i++)
		{
			// cout << "denum: " << denum << ", i: " << i << endl;
			if(3*i > denum && 2*i < denum && gcd(i, denum) == 1) ans++;
		}
	}
	cout << ans;
}