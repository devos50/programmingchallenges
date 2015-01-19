/*
 ID: mdmarti1
 PROG: msquare
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> target;
vector<int> begin;

string bfs()
{
	queue<vector<int> > q;
	map<vector<int>, string> seen;
	q.push(begin);
	seen[begin] = "";
	
	while(q.size() != 0)
	{
		vector<int> cur = q.front(); q.pop();
		string curstr = seen[cur];
		// cout << "str: " << curstr << endl;
		// cout << "vec: ";
		// for(vector<int>::iterator it = cur.begin(); it != cur.end(); it++) cout << *it << " ";
		// cout << endl;
		
		if(cur == target)
			return curstr;
			
		// operation A
		vector<int> newa = cur;
		reverse(newa.begin(), newa.end());
		if(seen.find(newa) == seen.end())
		{
			q.push(newa);
			seen[newa] = curstr + "A";
		}
		// operation B
		vector<int> newb1; for(int i = 0; i < 4; i++) newb1.push_back(cur[i]);
		vector<int> newb2; for(int i = 4; i < 8; i++) newb2.push_back(cur[i]);
		rotate(newb1.begin(), newb1.begin() + 3, newb1.end());
		rotate(newb2.begin(), newb2.begin() + 1, newb2.end());
		vector<int> newb;
		for(int i = 0; i < 4; i++) newb.push_back(newb1[i]);
		for(int i = 0; i < 4; i++) newb.push_back(newb2[i]);
		
		if(seen.find(newb) == seen.end())
		{
			q.push(newb);
			seen[newb] = curstr + "B";
		}
		
		// operation C
		vector<int> newc = cur;
		newc[1] = cur[6];
		newc[2] = cur[1];
		newc[5] = cur[2];
		newc[6] = cur[5];
		if(seen.find(newc) == seen.end())
		{
			q.push(newc);
			seen[newc] = curstr + "C";
		}
	}
	
	return "";
}

int main()
{
    ofstream fout ("msquare.out");
    ifstream fin ("msquare.in");

	for(int i = 1; i <= 8; i++) begin.push_back(i);
	for(int i = 0; i < 8; i++) { int n; fin >> n; target.push_back(n); };
	
	string ans = bfs();
	fout << ans.size() << endl;
	fout << bfs() << endl;

    return 0;
}