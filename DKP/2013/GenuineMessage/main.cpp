#include <iostream>

using namespace std;

void solve()
{
	string s; cin >> s;
	int freq[26]; for(int i = 0; i < 26; i++) freq[i] = 0;
	for(int i = 0; i < s.length(); i++)
	{
		freq[s[i] - 'A']++;
		if(freq[s[i] - 'A'] == 3)
		{
			freq[s[i] - 'A'] = 0;
			if(s[i+1] != s[i])
			{
				cout << "FAKE" << endl;
				return;
			}
			else
			{
				i++;
			}
		}
	}
	cout << "OK" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}