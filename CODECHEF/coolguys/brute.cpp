#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[]) 
{
	for(int n = 1; n < 30; n++)
	{
		int c = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = 1; b <=n; b++)
			{
				if(gcd(a, b) == b) c++;
			}
		}
		cout << "n: " << n << ", " << c << " / " << n * n << endl;

	}
}