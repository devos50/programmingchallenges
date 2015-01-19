#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	
	// contains all uppercase chars?
	bool upp = true;
	for(int i = 0; i < s.size(); i++)
		if(!(s[i] >= 'A' && s[i] <= 'Z')) upp = false;
		
	// all letters except first one upper case?
	bool upp2 = true;
	for(int i = 1; i < s.size(); i++)
		if(!(s[i] >= 'A' && s[i] <= 'Z')) upp2 = false;
	
	if(upp || upp2)
	{
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
			else s[i] = toupper(s[i]);
		}
		cout << s << endl;
	}
	else cout << s << endl;
}