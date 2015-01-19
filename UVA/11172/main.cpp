#include <iostream>

using namespace std;

void solve()
{
	long a, b; cin >> a >> b;
	if(a < b) cout << "<" << endl;
	else if(a > b) cout << ">" << endl;
	else cout << "=" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}