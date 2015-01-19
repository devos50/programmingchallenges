#include <iostream>

using namespace std;

bool isprime(int num)
{
	if(num == 0 || num == 1) return false;
	for(int i = 3; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}

int main(int argc, char *argv[]) 
{
	int primes = 3;
	int size = 2;
	
	int llr = 3;
	int lur = 9;
	int lll = 5;
	int lul = 7;
	
	while(true)
	{
		llr = 2 + llr + 8*(size - 1);
		lur = 8 + lur + 8*(size - 1);
		lll = 4 + lll + 8*(size - 1);
		lul = 6 + lul + 8*(size - 1);
		
		if(isprime(llr)) primes++;
		if(isprime(lur)) primes++;
		if(isprime(lll)) primes++;
		if(isprime(lul)) primes++;
		
		double ratio = (double)primes / (double)(2 * (size * 2 + 1) - 1);
		if(ratio < 0.1)
		{
			cout << "size: " << size * 2 + 1 << endl;
			return 0;
		}
		size++;
	}
}