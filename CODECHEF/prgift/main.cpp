#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
	int n, k; cin >> n >> k;
	int arr[n];
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i] % 2 == 0) count++;
	}
	
	if(k == 0 && count == n) cout << "NO" << endl;
	else if(count >= k) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}