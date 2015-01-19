#include <iostream>
#include <sstream>

using namespace std;

bool is_vowel(char c)
{
	return (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i' ||
			c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I');
}

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	stringstream ans;
	for(int i = 0; i < s.size(); i++)
	{
		if(is_vowel(s[i])) continue;
		
		char c = s[i];
		c = tolower(c);
		ans << '.' << c;
	}
	cout << ans.str() << endl;
}