#include <iostream>

using namespace std;

void solve()
{
	int n; cin >> n;
	if(n % 2  == 0) cout << "ALICE" << endl;
	else cout << "BOB" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}