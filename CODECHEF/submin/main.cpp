#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
	
	int minvals[n][n];
	for(int y = 0; y < n; y++)
		for(int x = 0; x < n; x++)
			minvals[y][x] = 0;
			
	// base cases
	for(int i = 0; i < n; i++) minvals[i][i] = arr[i];
	
	// process the array
	for(int y = 0; y < n; y++)
	{
		for(int x = y + 1; x < n; x++)
		{
			minvals[y][x] = min(minvals[y][x-1], arr[x]);
		}
	}
	
	// answer the queries
	int q; cin >> q;
	for(int i = 0; i < q; i++)
	{
		int k; cin >> k;
		int ans = 0;
		for(int y = 0; y < n; y++)
		{
			for(int x = y; x < n; x++)
			{
				if(minvals[y][x] == k) ans++;
			}
		}
		cout << ans << endl;
	}
	
}