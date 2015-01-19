#include <iostream>

using namespace std;

void solve()
{
	string s; cin >> s;
	string lstr = s.substr(0, s.size() / 2);
	string rstr = s.substr(s.size() / 2, s.size() / 2);
	if(s.size() % 2 == 1) rstr = s.substr(s.size() / 2 + 1, s.size() / 2);
	
	// cout << "l: " << lstr << ", r: " << rstr << endl;
	
	int freq1[50], freq2[50];
	for(int i = 0; i < 50; i++) freq1[i] = 0, freq2[i] = 0;
	
	for(int i = 0; i < lstr.size(); i++)
	{
		freq1[lstr[i] - 'a']++;
		freq2[rstr[i] - 'a']++;
	}
	
	for(int i = 0; i < 30; i++)
	{
		if(freq1[i] != freq2[i])
		{
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
	return;
	
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}