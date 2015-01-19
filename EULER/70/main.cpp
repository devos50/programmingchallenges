#include <iostream>

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

bool isPalindrome(int a, int b)
{
	int freq1[10], freq2[10];
	for(int i = 0; i < 10; i++) freq1[i] = 0, freq2[i] = 0;
	
	int cp1 = a, cp2 = b;
	while(cp1 != 0)
	{
		int dig = cp1 % 10;
		cp1 /= 10;
		freq1[dig]++;
	}
	while(cp2 != 0)
	{
		int dig = cp2 % 10;
		cp2 /= 10;
		freq2[dig]++;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(freq1[i] != freq2[i]) return false;
	}
	return true;
}

int main(int argc, char *argv[]) 
{
	int minn = -1;
	double minfrac = 100000;
	for(int i = 2; i < 10000000; i++)
	{
		if(i % 100000 == 0) cout << "i: " << i << endl;
		int eulertot = eulerTotient(i);
		if(!isPalindrome(eulertot, i)) continue;
		if((double)i / (double)eulertot < minfrac)
		{
			minfrac = (double)i / (double)eulertot;
			minn = i;
		}
	}
	
	cout << minn;
}