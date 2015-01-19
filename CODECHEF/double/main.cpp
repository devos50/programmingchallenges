#include <iostream>

using namespace std;

void solve()
{
	int n; cin >> n;
	if(n % 2 == 1) // oneven
	{
		cout << n - 1 << endl;
	}
	else cout << n << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}