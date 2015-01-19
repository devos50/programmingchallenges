#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define LINT 2100000000
#define MAX 5842

int dp[MAX];

void precalculate()
{
	dp[0] = 1;
	int ptr2 = 0, ptr3 = 0, ptr5 = 0, ptr7 = 0;
	for(int i = 1; i < MAX; i++)
	{
		int fac2 = dp[ptr2] * 2;
		int fac3 = dp[ptr3] * 3;
		int fac5 = dp[ptr5] * 5;
		int fac7 = dp[ptr7] * 7;
		
		if(fac2 <= fac3 && fac2 <= fac5 && fac2 <= fac7) 
		{
			dp[i] = fac2;
			ptr2++;
		}
		if(fac3 <= fac2 && fac3 <= fac5 && fac3 <= fac7)
		{
			dp[i] = fac3;
			ptr3++;
		}
		if(fac5 <= fac2 && fac5 <= fac3 && fac5 <= fac7)
		{
			dp[i] = fac5;
			ptr5++;
		}
		if(fac7 <= fac2 && fac7 <= fac3 && fac7 <= fac5)
		{
			dp[i] = fac7;
			ptr7++;
		}
	}
}

int main(int argc, char *argv[]) 
{
	precalculate();
	
	while(true)
	{
		int n; cin >> n;
		if(n == 0) break;
		
		int lastdig = n % 10;
		
		// suffix logic
		string suffix;
		if((n / 10) % 10 == 1) suffix = "th";
		else
		{
			string tab[10] = { "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th" };
			suffix = tab[n % 10];
		}
		
		cout << "The " << n << suffix << " humble number is " << dp[n-1] << "." << endl;
	}
}