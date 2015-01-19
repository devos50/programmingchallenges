#include <iostream>
#include <map>

using namespace std;

void solve()
{
	int n; cin >> n;
	string s_arr[1005];
	
	map<int, int> word_map;
	
	// read public key
	for(int i = 0; i < n; i++)
		cin >> s_arr[i];
		
	// read other public key
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for(int j = 0; j < n; j++)
		{
			if(s_arr[j] == s)
				word_map[j] = i;
		}
	}
	
	// read plaintext
	string txt[1005];
	for(int i = 0; i < n; i++)
		cin >> txt[i];
		
	for(int i = 0; i < n; i++)
	{
		cout << txt[word_map[i]];
		if(i != n - 1) cout << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}