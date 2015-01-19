#include <iostream>
#include <cmath>

using namespace std;

int n;
int cap_sal[10005];
int ass_sal[10005];

int main(int argc, char *argv[]) 
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> cap_sal[i] >> ass_sal[i];
	
	int dp1[10005];
	int dp2[10005];
	
	// base case
	for(int i = 0; i < n; i++) dp2[i] = 0;
	
	for(int cur = n - 1; cur > 0; cur--)
	{
		for(int captains = n / 2; captains >= 0; captains--)
		{
			if(cur - captains == n / 2) dp1[captains] = cap_sal[cur] + dp2[captains + 1];
			else if(cur % 2 == 0 && captains == cur - captains) dp1[captains] = ass_sal[cur] + dp2[captains];
			else dp1[captains] = min(cap_sal[cur] + dp2[captains + 1], ass_sal[cur] + dp2[captains]);
		}
		
		// copy contents of dp1 to dp2
		for(int i = 0; i < n; i++) dp2[i] = dp1[i];
	}
	cout << ass_sal[0] + dp2[0] << endl;
}