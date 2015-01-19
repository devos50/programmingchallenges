#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string lowercase(string s)
{
	for(int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}

bool isPalindrome(string s)
{
	// remove the spaces, commas etc
	s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
	s.erase( remove( s.begin(), s.end(), '.' ), s.end() );
	s.erase( remove( s.begin(), s.end(), ',' ), s.end() );
	s.erase( remove( s.begin(), s.end(), '!' ), s.end() );
	s.erase( remove( s.begin(), s.end(), '?' ), s.end() );
	s = lowercase(s);
	
	// cout << s << endl;
	
	return (s == string(s.rbegin(), s.rend()));
}

int main(int argc, char *argv[]) 
{
	string s;
	while(getline(cin, s))
	{
		if(s == "DONE") break;
		if(isPalindrome(s)) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
}