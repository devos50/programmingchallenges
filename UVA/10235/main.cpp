#include <iostream>
#include <cstdio>

using namespace std;

bool is_prime(int n)
{
	if(n == 0 || n == 1) return false;
	else if(n == 2) return true;
	else if(n % 2 == 0) return false;
	
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0) return false;
	return true;
}

int reverse(int n)
{
	int reverse = 0;
	for(; n != 0 ;)
	{
		reverse = reverse * 10;
	    reverse = reverse + n % 10;
	    n = n / 10;
	}
	
	// cout << "n: " << n << ", reverse: " << reverse << endl;
	
	return reverse;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n)
	{
		if(is_prime(n)) 
		{
			if(is_prime(reverse(n)) && n != reverse(n)) 
			{
				printf("%d is emirp.\n", n);
		    } 
			else 
			{
		        printf("%d is prime.\n", n);
		        
			}
		} 
		else 
		{
		       printf("%d is not prime.\n", n);
		}
	}
}