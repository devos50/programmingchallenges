#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

long findN(long a, long b)
{
	// cout << "a: " << a << ", b: " << b << endl;
	bool found = false;
	long n = 1;
	while(!found)
	{
		double exp = log(b) / log(n);
		double l = pow(n+1, exp);
		long llong = round(l);
		double diff = (double)a - l;
		if(diff < 0) diff *= -1.0;
		if(diff < 0.001)
		{
			break;
		}
		n++;
	}
	
	return n;
}

void solve(long a, long b)
{
	long n = 1;
	if(b != 1) n = findN(a, b);
	long h = 0;
	if(log(n) == 0) h = round(log(a) / log(2));
	else h = round(log(b) / log(n));
	// cout << "n: " << n << ", h: " << h << endl;
			
	// find the number of non-working cats
	long notworking = 0;
	for(int i = 0; i <= h - 1; i++)
	{
		notworking += pow(n, i);
	}
	
	// find the height of the stack
	long stackheight = 0;
	for(int i = 0; i <= h; i++)
	{
		stackheight += pow(n, i) * (a / pow(n+1, i));
	}
	cout << notworking << " " << stackheight << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		long a, b; cin >> a >> b;
		if(a == 0 && b == 0) break;
		solve(a, b);
	}
}