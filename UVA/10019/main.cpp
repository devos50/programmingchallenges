#include <iostream>

using namespace std;

int count(long long n)
{
	int ans = 0;
	string s;
	while(n != 0)
	{
		if(n % 2 == 1) ans++;
		n /= 2;
	}
	return ans;
}

int hexcount(int n)
{
	int ans = 0;
	while(n != 0)
	{
		int dig = n % 10;
		if(dig == 1) ans += 1;
		else if(dig == 2) ans += 1;
		else if(dig == 3) ans += 2;
		else if(dig == 4) ans += 1;
		else if(dig == 5) ans += 2;
		else if(dig == 6) ans += 2;
		else if(dig == 7) ans += 3;
		else if(dig == 8) ans += 1;
		else if(dig == 9) ans += 2;
		
		n /= 10;
	}
	return ans;
}

void solve()
{
	int n; cin >> n;
	cout << count(n) << " " << hexcount(n) << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}