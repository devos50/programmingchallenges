#include <iostream>

using namespace std;

void solve()
{
	long long n; cin >> n;
	n *= 63;
	n += 7492;
	n *= 5;
	n -= 498;
	n /= 10;
	
	int ans = n % 10;
	if(ans < 0) ans *= -1;
	
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}