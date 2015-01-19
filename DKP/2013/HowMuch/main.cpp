#include <iostream>

using namespace std;

void solve()
{
	int s, n; cin >> s >> n;
	int total = 0;
	for(int i = 0; i < n; i++)
	{
		int q, p; cin >> q >> p;
		total += q * p;
	}
	cout << s + total << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}