#include <iostream>

using namespace std;

void solve()
{
	int s, k; cin >> s >> k;
	if(k % 2 == 1) cout << (s % 2) << endl;
	else
	{
		if(s % (k + 1) == k) cout << k << endl;
		else cout << ((s % (k + 1)) % 2) << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}