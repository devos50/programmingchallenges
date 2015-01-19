#include <iostream>

using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	int sn = (n - 2) / 3;
	if((n - 2) % 3 != 0) sn++;
	int sm = (m - 2) / 3;
	if((m - 2) % 3 != 0) sm++;
	
	cout << sn * sm << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}