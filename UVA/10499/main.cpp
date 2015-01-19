#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long n; scanf("%lld", &n);
	while(n >= 0)
	{
		if(n == 0 || n == 1) { printf("0%\n"); }
		else { printf("%lld%%\n", 25*n); }
		
		scanf("%lld", &n);
	}
}