#include <iostream>

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

using namespace std;

int main(int argc, char *argv[]) 
{
	double maxfrac = -1;
	int maxn = 0;
	for(int n = 2; n <= 1000000; n++)
	{
		int eulertot = eulerTotient(n);
		double frac = (double)n / (double)eulertot;
		if(frac > maxfrac) { maxfrac = frac; maxn = n; }
	}
	cout << maxn << endl;
}