#include <iostream>
#include <cmath>

using namespace std;

int eulerTotient(int n) 
{ 
   int result = n; 
   for(int i=2;i*i <= n;i++) 
   { 
      if (n % i == 0) result -= result / i; 
      while (n % i == 0) n /= i; 
    } 
    if (n > 1) result -= result / n; 
    return result; 
} 

int main(int argc, char *argv[]) 
{
	long long ans = 0;
	for(int i = 2; i <= 1000000; i++)
	{
		if(i % 10000 == 0) cout << i << endl;
		// cout << "i: " << i << ", divs: " << i - divisors(i) + 1 << endl;
		ans += eulerTotient(i);
	}
	cout << ans << endl;
}