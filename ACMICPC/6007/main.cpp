#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int w; cin >> w;
	vector<string> before;
	vector<string> after;
	string word;
	bool before_word = true;
	for(int i = 0; i < w; i++)
	{
		string s; cin >> s;
		if(s[0] != '#')
		{
			before_word = false;
			word = s;
		}
		else if(before_word)
		{
			before.push_back(s);
		}
		else
		{
			after.push_back(s);
		}
	}
	
	if(before_word)
	{
		// not corrupt
		for(vector<string>::iterator it = before.begin(); it != before.end(); it++)
		{
			cout << *it;
			if((it + 1) != before.end()) cout << " ";
		}
		cout << endl;
	}
	else
	{
		for(vector<string>::iterator it = after.begin(); it != after.end(); it++)
		{
			cout << *it << " ";
		}
		cout << word;
		if(before.size() != 0) cout << " ";
		for(vector<string>::iterator it = before.begin(); it != before.end(); it++)
		{
			cout << *it;
			if((it + 1) != before.end()) cout << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}