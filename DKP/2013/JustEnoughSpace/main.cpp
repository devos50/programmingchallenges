#include <iostream>
#include <cmath>

using namespace std;

int n, e;
bool dp1[400005];
bool dp2[400005];

void solve()
{
	cin >> n >> e;
	
	for(int i = 0; i < 400005; i++) dp1[i] = false;
	for(int i = 0; i < 400005; i++) dp2[i] = false;
	dp1[0] = true;
	dp2[0] = true;
	
	// dp
	int sizes[n];
	int maxsum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> sizes[i];
		sizes[i] *= 2;
		maxsum += sizes[i];
	}
	
	for(int i = 0; i < n; i++) 
	{
		int size = sizes[i];
		// base case
		dp2[size] = true;
		for(int i = 0; i < maxsum + 5 - size; i++)
		{
			if(dp1[i])
			{
				dp2[i + size] = true;
			}
		}
		
		// copy dp2 -> dp1
		for(int i = 0; i < maxsum + 5; i++) dp1[i] = dp2[i];
	}
	
	bool can = false;
	for(int i = e; i <= maxsum + 5; i++)
	{
		if(dp1[i]) { cout << i / 2 << endl; can = true; break; }
	}
	if(!can) cout << "FULL" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}