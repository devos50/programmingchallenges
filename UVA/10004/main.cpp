#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool dfs(int x, bool c, int colors[], map<int, vector<int> > edges)
{
	colors[x] = c ? 1 : 0;
	for(vector<int>::iterator it = edges[x].begin(); it != edges[x].end(); it++)
	{
		if(colors[*it] != -1 && colors[*it] == colors[x]) return false;
		else if(colors[*it] != -1 && colors[*it] != colors[x]) continue;
		dfs(*it, !c, colors, edges);
	}
	return true;
}

void solve(int n)
{
	int colors[n];
	map<int, vector<int> > edges;
	for(int i = 0; i < n; i++) colors[i] = -1;
	int numEdges; cin >> numEdges;
	
	for(int i = 0; i < numEdges; i++)
	{
		int e1, e2; cin >> e1; cin >> e2;
		edges[e1].push_back(e2);
		edges[e2].push_back(e1);
	}
	
	bool pos = dfs(0, true, colors, edges);
	if(pos) cout << "BICOLORABLE." << endl;
	else cout << "NOT BICOLORABLE." << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int n;
		cin >> n;
		if(n == 0) return 0;
		solve(n);
	}
}