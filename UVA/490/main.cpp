#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	string a, b;
	vector<string> strings;
	string curstring;
	int longest = 0;
	while(getline(cin, curstring))
	{
		if(longest < curstring.size()) longest = curstring.size();
		strings.push_back(curstring);
	}
	
	for(int i = 0; i < longest; i++)
	{
		// iterate over the strings
		for(vector<string>::reverse_iterator it = strings.rbegin(); it != strings.rend(); it++)
		{
			string cur = *it;
			if(i >= cur.size()) cout << " ";
			else cout << cur.at(i);
		}
		cout << endl;
	}
}