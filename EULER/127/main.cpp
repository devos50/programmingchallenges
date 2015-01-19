#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while(true)
	{
		a = a % b;
		if(a == 0) return b;
		b = b % a;
		if(b == 0) return a;
	}
}

int main(int argc, char *argv[]) 
{
	for(int c = 3; c < 1000; c++)
	{
		for(int a = 1; a < c / 2; a++)
		{
			int b = c - a;
			if(gcd(a, c) == 1 && gcd(b, c) == 1) cout << "(" << a << ", " << b << ", " << c << ")" << endl;
		}
	}
}