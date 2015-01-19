#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	set<char> chars;
	for(int i = 0; i < s.size(); i++)
		chars.insert(s[i]);
		
	if(chars.size() % 2 == 0) cout << "CHAT WITH HER!" << endl;
	else cout << "IGNORE HIM!" << endl;
}