#include <iostream>
#include <vector>

using namespace std;

bool isprime(int num)
{
	if(num < 0) return false;
	if(num == 0 || num == 1) return false;
	if(num == 2) return true;
	if(num % 2 == 0) return false;
	for(int i = 3; i * i <= num; i+=2)
		if(num % i == 0) return false;
	return true;
}

int main(int argc, char *argv[]) 
{
	int max = 1000000;
	vector<long long> primes;
	for(long long i = 2; i < 1000000; i++)
		if(isprime(i)) { primes.push_back(i); }
		
	// calculate cummulative sum
	long long cumsum[primes.size()];
	cumsum[0] = primes[0];
	for(int i = 1; i < primes.size(); i++) cumsum[i] = cumsum[i-1] + primes[i];
		
	// iterate over every length
	for(int length = primes.size(); length >= 1; length--)
	{
		for(int leftind = 0; leftind <= primes.size() - length; leftind++)
		{
			long long sum = 0;
			if(leftind == 0) sum = cumsum[leftind + length - 1];
			else sum = cumsum[leftind + length - 1] - cumsum[leftind - 1];
			
			if(sum < max && isprime(sum))
			{
				cout << "length: " << length << ", sum: " << sum << ", left index: " << leftind << endl;
				return 0;
			}
		}
	}
}