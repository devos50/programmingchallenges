#include <iostream>
#include <list>

using namespace std;

void solve(string s)
{
	list<char> text;
	list<char>::iterator it = text.begin();
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '[') it = text.begin();
		else if(s[i] == ']') { it = text.end(); }
		else text.insert(it, s[i]);
	}
	
	// print end result
	for(it = text.begin(); it != text.end(); it++) cout << *it;
	cout << endl;
}

int main(int argc, char *argv[])
{
	string s;
	while(cin >> s) solve(s);
}