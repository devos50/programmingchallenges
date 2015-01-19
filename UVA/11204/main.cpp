#include <iostream>

using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	int arr[m][n];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
			
	// count ones
	int ans = 1;
	for(int x = 0; x < n; x++)
	{
		int ones = 0;
		for(int y = 0; y < m; y++)
		{
			if(arr[y][x] == 1) ones++;
		}
		if(ones == 0) continue;
		else ans *= ones;
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}