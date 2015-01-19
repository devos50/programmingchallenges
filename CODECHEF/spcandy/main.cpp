#include <iostream>

using namespace std;

void solve()
{
	long long n, k; cin >> n >> k;
	if(k == 0)
	{
		cout << "0 " << n << endl;
	}
	else if(n == 0)
	{
		cout << "0 0" << endl;
	}
	else cout << n / k << " " << n % k << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}