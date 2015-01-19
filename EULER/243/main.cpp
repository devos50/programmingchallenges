#include <iostream>

#define L 80

using namespace std;

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

int main(int argc, char *argv[]) 
{
	// calculate phi(2 * 3 * ... * 23)
	int n = 1;
	int phi = 1;
	for(int i = 0; i <= 8; i++)
	{
		phi *= (primes[i] - 1);
		n *= primes[i];
	}
	
	double ratio = (double)phi / (double)(n - 1);
	while(ratio >= 15499.0 / 94744.0)
	{
		n *= 2;
		phi *= 2;
		ratio = (double)phi / (double)(n - 1);
	}
	
	cout << "n: " << n << endl;
	cout << "ratio: " << (double)phi / (double)(n - 1) << endl;
	
}