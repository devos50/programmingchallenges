#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map<int, vector<int> > adj;

int main(int argc, char *argv[]) 
{
	int n, m, s; cin >> n >> m >> s;
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		
		// add a direction to both sides
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	// bfs
	queue<int> q; q.push(s);
	bool visited[n]; 
	for(int i = 0; i < n; i++) visited[i] = false;
	
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		
		for(vector<int>::iterator it = adj[cur].begin(); it != adj[cur].end(); it++)
		{
			int node = *it;
			if(!visited[node])
			{
				visited[node] = true;
				q.push(node);
			}
		}
	}
	
	// check if everything is checked
	bool good = true;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			good = false;
			break;
		}
	}
	
	cout << ((good) ? "yes" : "no");
	cout << endl;
}