#include <iostream>

using namespace std;

int incans = 0;
int decans = 0;
int maxdigits;
long long dp[105][11];

long long finc(int lleft, int lastdig)
{	
	if(lleft == -1) return 0;
	if(dp[lleft][lastdig] != -1) return dp[lleft][lastdig];
	
	long long ans = 1;
	if(lleft == maxdigits) ans = 0;
	
	if(lleft == maxdigits)
		for(int i = 1; i < 10; i++) ans += finc(lleft - 1, i);
	else
		for(int i = lastdig; i < 10; i++) ans += finc(lleft - 1, i);
	
	dp[lleft][lastdig] = ans;
	return ans;
}

long long fdec(int lleft, int lastdig)
{	
	if(lleft == -1) return 0;
	if(dp[lleft][lastdig] != -1) return dp[lleft][lastdig];
	
	long long ans = 1;
	if(lleft == maxdigits) ans = 0;
	
	if(lleft == maxdigits)
		for(int i = 9; i > 0; i--) ans += fdec(lleft - 1, i);
	else
		for(int i = lastdig; i > -1; i--) ans += fdec(lleft - 1, i);
	
	dp[lleft][lastdig] = ans;
	return ans;
}

void resetdp()
{
	for(int y = 0; y < 105; y++)
			for(int x = 0; x < 11; x++)
				dp[y][x] = -1;
}

int main(int argc, char *argv[]) 
{
	resetdp();
	maxdigits = 100;
	
	long long int incnums = finc(maxdigits, 1);
	resetdp();
	long long int decnums = fdec(maxdigits, 9);
	cout << "increasing numbers: " << incnums << ", decreasing numbers: " << decnums << endl;
	
	cout << "ans: " << incnums + decnums - maxdigits * 9 << endl;
}