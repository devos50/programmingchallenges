#include <iostream>

using namespace std;

void solve()
{
	string s; cin >> s;
	int freq[27];
	for(int i = 0; i < 27; i++) freq[i] = 0;
	for(int i = 0; i < s.size(); i++) freq[s[i] - 'A']++;
	
	char needed[9] = {'M', 'A', 'R', 'G', 'A', 'R', 'I', 'T', 'A'};
	
	int pizzas = 0;
	while(true)
	{
		for(int i = 0; i < 9; i++)
		{
			if(freq[needed[i] - 'A'] == 0) { cout << pizzas << endl; return; }
			freq[needed[i] - 'A']--;
		}
		pizzas++;
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}