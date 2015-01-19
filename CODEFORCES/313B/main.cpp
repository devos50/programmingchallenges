#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	int n; cin >> n;
	
	int dp[s.size()];
	for(int i = 1; i <= n; i++)
	{
		if(s[i-1] == )
	}
	
	for(int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		l--; r--; int ans = 0;
		for(int j = l; j < r; j++)
		{
			if(s[j] == s[j+1]) ans++;
		}
		cout << ans << endl;
	}
}