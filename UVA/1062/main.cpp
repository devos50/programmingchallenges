#include <iostream>
#include <vector>
#include <stack>

#define LINT 1000000000

using namespace std;

void solve(string s, int c)
{
	vector<stack<char> > stacks;
	for(int i = 0; i < s.size(); i++)
	{
		char curchar = s[i];
		
		int mindist = LINT;
		int minind = -1;
		int curind = 0;
		for(vector<stack<char> >::iterator it = stacks.begin(); it != stacks.end(); it++)
		{
			stack<char> curstack = *it;
			char topchar = curstack.top();
			// cout << "top char: " << topchar << ", cur char: " << curchar << endl;
			if(topchar < curchar) { curind++; continue; }
			
			if(topchar - curchar < mindist)
			{
				mindist = topchar - curchar;
				minind = curind;
			}
			curind++;
		}
		
		if(minind == -1)
		{
			// cout << "CREATING NEW STACK" << endl;
			stack<char> newstack;
			newstack.push(curchar);
			stacks.push_back(newstack);
		}
		else
		{
			// cout << "ADDING TO EXISTING" << endl;
			stack<char> thestack = stacks[minind];
			thestack.push(curchar);
			stacks[minind] = thestack;
		}
	}
	cout << "Case " << c << ": " << stacks.size() << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	int c = 1;
	while(cin >> s)
	{
		if(s == "end") break;
		solve(s, c);
		c++;
	}
}