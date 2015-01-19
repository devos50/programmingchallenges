#include <iostream>
#include <stack>

using namespace std;

void solve()
{
	string s; getline(cin, s);
	stack<char> st;
	for(int i = 0; i < s.size(); i++)
	{
		if(s.at(i) == ' ') continue;
		if(s.at(i) == '(' || s.at(i) == '[') st.push(s.at(i));
		else if(s.at(i) == ']')
		{
			if(st.size() == 0 || st.top() != '[')
			{
				cout << "No" << endl;
				return;
			}
			else st.pop();
		}
		else if(s.at(i) == ')')
		{
			if(st.size() == 0 || st.top() != '(')
			{
				cout << "No" << endl;
				return;
			}
			else st.pop();
		}
	}
	
	if(st.size() == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	string s; getline(cin, s);
	while(t--) solve();
}