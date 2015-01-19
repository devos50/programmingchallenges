#include <iostream>
#include <algorithm>

using namespace std;

void solve(string s)
{
	next_permutation(s.begin(), s.end());
	// check increasing
	int cur = s.at(0); bool inc = true;
	for(int i = 1; i < s.size(); i++)
	{
		if(cur > s.at(i))
		{
			inc = false;
			break;
		}
		cur = s.at(i);
	}
	if(inc) cout << "No Successor" << endl;
	else cout << s << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	while(getline(cin, s))
	{
		if(s == "#") break;
		solve(s);
	}
}