#include <iostream>

using namespace std;

void solve()
{
	long long num; cin >> num;
	if(num % 2 == 0) cout << num * (num + 2) * (2 * num + 1) / 8 << endl;
	else cout << (num * (num + 2) * (2 * num + 1) - 1) / 8 << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}