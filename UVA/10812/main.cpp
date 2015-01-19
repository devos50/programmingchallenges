#include <iostream>

using namespace std;

void solve()
{
	int s, d;
	cin >> s >> d;
	
	int b2 = s - d;
	if(b2 < 0 || b2 % 2 == 1)
	{
		cout << "impossible" << endl;
		return;
	}
	
	int b = b2 / 2;
	int a = s - b;
	if(a > b) cout << a << " " << b << endl;
	else cout << b << " " << a << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}