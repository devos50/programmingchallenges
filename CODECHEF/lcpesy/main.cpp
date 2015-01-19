#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
	string str1, str2; cin >> str1 >> str2;
	int freq1[260], freq2[260];
	for(int i = 0; i < 260; i++)
	{
		freq1[i] = 0;
		freq2[i] = 0;
	}
	
	for(int i = 0; i < str1.length(); i++) freq1[str1[i]]++;
	for(int i = 0; i < str2.length(); i++) freq2[str2[i]]++;
	
	int ans = 0;
	for(int i = 0; i < 260; i++) ans += min(freq1[i], freq2[i]);
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}