#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> rec(set<int> s)
{
	
	
	return s;
}

void solve()
{
	set<int> s;
	int c; cin >> c;
	s.insert(c);
	set<int> ans = rec(s);
	
	vector<int> v_ans;
	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
		v_ans.push_back(*it);
		
	for(int i = 0; i < v_ans.size(); i++)
	{
		cout << v_ans[i];
		if(i != v_ans.size() - 1) cout << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}