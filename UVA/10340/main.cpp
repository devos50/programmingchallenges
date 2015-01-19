#include <iostream>

using namespace std;

void solve(string s, string t)
{
	int curpointer = 0;
	for(int i = 0; i < t.size(); i++)
	{
		if(curpointer == s.size()) break;
		if(t.at(i) == s.at(curpointer)) curpointer++;
	}
	if(curpointer == s.size()) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main(int argc, char *argv[]) 
{
	string s, t;
	while(cin >> s >> t) solve(s, t);
}