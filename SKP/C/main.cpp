#include <iostream>
#include <cmath>

using namespace std;

int A(int a, int b)
{
	if((a&b) == 0) return a ^ b; else return A(a^b, (a&b) << 1);
}

int B(int a, int b)
{
	if(a < b) return a; else return a - b;
}

int C(int a, int b)
{
	if(a == 0) return 0; else return B(A(C(a-1,b),1),b);
}

int D(int a, int b)
{
	if(a*a >= b) return a; else return D(a+1,b);
}

void F(int n)
{
	for(int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for(int j = 1; j <= i; j++)
		{
			if(C(i, j) == 0) cnt++;
		}
		if(cnt == 3) cout << D(1,i) << endl;
	}
}

bool isPrime(int n)
{
	if(n == 2) return true;
	if(n == 0 || n % 2 == 0) return false;
	for(int i = 3; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}

void newF(int n)
{
	int s = sqrt(n);
	for(int i = 2; i <= s; i++)
	{
		if(isPrime(i)) cout << i << endl;
	}
}

int main(int argc, char *argv[]) {
	int n; cin >> n;
	newF(n);
}