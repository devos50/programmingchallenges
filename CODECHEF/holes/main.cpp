#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--)
	{
		int ans = 0;
		string s; cin >> s;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == 'A' || s[i] == 'D' || s[i] == 'O' || s[i] == 'P' || s[i] == 'Q' || s[i] == 'R') ans += 1;
			if(s[i] == 'B') ans += 2;
		}
		cout << ans << endl;
	}
}