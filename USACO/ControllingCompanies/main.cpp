/*
 ID: mdmarti1
 PROG: concom
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

#define LINT 10000

using namespace std;

int companies[105][105];
set<int> comps;

map<int, vector<int> > controlling;

void bfs(int start)
{
	queue<int> q;
	map<int, int> commap;
	q.push(start);
	commap[start] = 100;
	while(q.size() != 0)
	{
		int cur = q.front(); q.pop();
		for(int i = 0; i < 105; i++)
		{
			if(companies[cur][i] != LINT) // if cur owns i
			{
				if(commap.find(i) == commap.end()) // if this company has not been seen
				{ 
					commap[i] = companies[cur][i];
					if(companies[cur][i] > 50) q.push(i); // if we control this company, expand it
				}
				else // if we've already seen the company
				{
					int owning = commap[i];
					if(owning > 50) continue;
					if(owning + companies[cur][i] > 50) // if we now own this company
					{
						q.push(i);
						commap[i] = owning + companies[cur][i];
					}
					else
					{
						commap[i] = owning + companies[cur][i];
					}
				}
			}
		}
	}
	
	vector<int> res;
	for(map<int, int>::iterator it = commap.begin(); it != commap.end(); it++)
	{
		if(start == 34)
		{
			cout << "34 owning " << it->first << " for " << it->second << endl;
		}
		if(it->first != start && it->second > 50) res.push_back(it->first);
	}
	controlling[start] = res;
}

int main()
{
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");

	for(int i = 0; i < 105; i++)
		for(int j = 0; j < 105; j++)
			companies[i][j] = LINT;

	int n; fin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, b, c; fin >> a >> b >> c;
		comps.insert(a); comps.insert(b);
		companies[a][b] = c;
	}
	
	// do a bfs from each company
	for(set<int>::iterator it = comps.begin(); it != comps.end(); it++)
		bfs(*it);
	
	// print result
	for(map<int, vector<int> >::iterator it = controlling.begin(); it != controlling.end(); it++)
	{
		vector<int> res = it->second;
		sort(res.begin(), res.end());
		for(vector<int>::iterator it2 = res.begin(); it2 != res.end(); it2++)
			fout << it->first << " " << *it2 << endl;
	}

    return 0;
}