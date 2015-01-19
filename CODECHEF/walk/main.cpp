#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
	int n; cin >> n;
	int vels[n];
	for(int i = 0; i < n; i++) cin >> vels[i];
	
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		// met welke snelheid moet ik langslopen?
		if(ans < vels[i] + i) ans = vels[i] + i;
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}