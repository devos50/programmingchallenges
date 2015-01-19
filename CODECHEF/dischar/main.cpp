#include <iostream>

using namespace std;

void solve()
{
	string s; cin >> s;
	int freq[26]; for(int i = 0; i < 26; i++) freq[i] = 0;
	
	for(int i = 0; i < s.size(); i++)
	{
		freq[s[i] - 'a']++;
	}
	
	int c = 0;
	for(int i = 0; i < 26; i++) 
	{
		if(freq[i] != 0) { c++; }
	}
	
	cout << c << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}