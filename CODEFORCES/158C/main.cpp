#include <iostream>
#include <vector>

using namespace std;

vector<string> dirtree;

vector<string> split(string text, char sep) 
{
	vector<string> tokens;
  	int start = 0, end = 0;
  	while ((end = text.find(sep, start)) != string::npos) 
	{
    	tokens.push_back(text.substr(start, end - start));
    	start = end + 1;
  	}
  	tokens.push_back(text.substr(start));

	return tokens;
}

void print_dir()
{
	if(dirtree.size() == 0) cout << "/" << endl;
	else
	{
		cout << "/";
		for(vector<string>::iterator it = dirtree.begin(); it != dirtree.end(); it++)
		{
			cout << *it << "/";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if(s == "pwd") print_dir();
		else
		{
			cin >> s;
			if(s[0] == '/') dirtree.clear();
			vector<string> parts = split(s, '/');
			for(vector<string>::iterator it = parts.begin(); it != parts.end(); it++)
			{
				if(*it == "") continue;
				if(*it == "..") dirtree.pop_back();
				else dirtree.push_back(*it);
			}
		}
	}
}