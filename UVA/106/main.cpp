#include <iostream>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

void solve(int num)
{
	bool isPart[num+1];
	for(int i = 0; i < num+1; i++) isPart[i] = false;
	int notPart = num;
	
	// generate triples
	int numTriples = 0;
	int max = (int)sqrt(num);
	for(int m = 2; m <= max; m++)
	{
		for(int n = 1; n < m; n++)
		{
			int a = m*m - n*n;
			int b = 2*m*n;
			int c = m*m + n*n;
			if(a <= num && b <= num && c <= num)
			{
				if(b < a)
				{
					int temp = b;
					b = a;
					a = temp;
				}
				if(a < b && b < c && gcd(a, b) == 1 && gcd(b, c) == 1) numTriples++;
								
				int multiplies = num / c;
				for(int i = 1; i <= multiplies; i++)
				{
					if(!isPart[i*a])
						notPart--;
					isPart[i*a] = true;
					if(!isPart[i*b])
						notPart--;
					isPart[i*b] = true;
					if(!isPart[i*c])
						notPart--;
					isPart[i*c] = true;
				}
			}
		}
	}
	cout << numTriples << " " << notPart << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n) solve(n);
}