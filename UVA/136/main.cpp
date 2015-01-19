#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int dp[1505];
	dp[1] = 1;
	int ptr2 = 1, ptr3 = 1, ptr5 = 1;
	for(int i = 2; i <= 1500; i++)
	{
		int fac2 = dp[ptr2] * 2;
		int fac3 = dp[ptr3] * 3;
		int fac5 = dp[ptr5] * 5;
		
		if(fac2 <= fac3 && fac2 <= fac5) 
		{
			dp[i] = fac2;
			ptr2++;
		}
		if(fac3 <= fac2 && fac3 <= fac5)
		{
			dp[i] = fac3;
			ptr3++;
		}
		if(fac5 <= fac2 && fac5 <= fac3)
		{
			dp[i] = fac5;
			ptr5++;
		}
		
		// cout << "dp[" << i << "]: " << dp[i] << endl;
	}
	cout << dp[4] << endl;
	// cout << "The 1500'th ugly number is 859963392." << endl;
}