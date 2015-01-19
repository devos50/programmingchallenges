#include <iostream>

using namespace std;

void solve()
{
	string s; getline(cin, s);
	// cout << "S: " << s << endl;
	int bestd = -1, maxe = -1;
	for(int d = 0; d <= 25; d++)
	{
		int counte = 0;
		
		for(int i = 0; i < s.size(); i++)
		{
			if(s.at(i) >= 'A' && s.at(i) <= 'Z')
			{
				char newchar = (s.at(i) + d - 'A') % 26 + 'A';
				if(newchar == 'E') counte++;
			}
		}
		
		if(counte > maxe) { bestd = d; maxe = counte; }
		// else if(counte == maxe) { cout << "NOT POSSIBLE" << endl; return; }
	}
	
	cout << bestd << " ";
	for(int i = 0; i < s.size(); i++)
	{
		char newchar = (s.at(i) + bestd - 'A') % 26 + 'A';
		cout << newchar;
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	// string s; getline(cin, s);
	while(t--) solve();
}