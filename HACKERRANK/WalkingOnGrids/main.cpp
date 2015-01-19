#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int dp1[2005];
	int dp2[2005];
	
	dp1[0] = 1;
	for(int i = 1; i < n; i++)
	{
		dp2[0] = 1;
		for(int j = 1; j < i; j++)
		{
			dp2[j] = (dp2[j-1] + dp1[j] % 10007);
		}
		dp2[i] = dp2[i-1];
		
		// copy to dp1
		for(int i = 0; i < n; i++) dp1[i] = dp2[i];
	}
	
	// for(int i = 0; i < n; i++) cout << dp1[i] << " ";
	cout << (dp1[n-1] * 2) % 10007 << endl;
}