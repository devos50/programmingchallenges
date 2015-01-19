#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, m;
int s, t;
map<int, vector<int> > adj;
int capacity[500][500];

int find_path() 
{
	// bfs
	queue<int> q;
	q.push(s);
	bool visited[n+5]; for(int i = 0; i < n+5; i++) visited[i] = false;
	visited[s] = true;
	int from[n+5]; for(int i = 0; i < n+5; i++) from[i] = -1;
	while(q.size() != 0)
	{
		int cur = q.front(); q.pop();
		vector<int> vec = adj[cur];
		for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			if(!visited[*it] && capacity[cur][*it] > 0)
			{
				q.push(*it); visited[*it] = true; from[*it] = cur;
				if(*it == t) break;
			}
		}
	}
	
	// compute bottleneck
	int cur = t, path_cap = INT_MAX;
	while(from[cur] > -1)
	{
		int prev = from[cur];
		path_cap = min(path_cap, capacity[prev][cur]);
		cur = prev;
	}
	
	// augmentation
	cur = t;
	while(from[cur] > -1)
	{
		int prev = from[cur];
		capacity[prev][cur] -= path_cap;
		capacity[cur][prev] += path_cap;
		cur = prev;
	}
	
	if(path_cap == INT_MAX) return 0;
	else { return path_cap; }
}

int max_flow()
{
	int result = 0;
	while(true)
	{
		int path_capacity = find_path();
		if(path_capacity == 0) break;
		else result += path_capacity;
	}
	return result;
}

void find_mincut()
{
	bool sset[n+5]; for(int i = 0; i < n+5; i++) sset[i] = false;
	queue<int> q;
	q.push(s);
	bool visited[n+5]; for(int i = 0; i < n+5; i++) visited[i] = false;
	visited[s] = true;
	while(q.size() != 0)
	{
		int cur = q.front(); q.pop();
		sset[cur] = true;
		vector<int> vec = adj[cur];
		for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			// check if we can go to the right
			if(!visited[*it] && capacity[cur][*it] != 0)
			{
				q.push(*it); visited[*it] = true;
			}
		}
	}
	
	for(int i = 0; i < n+5; i++)
	{
		if(sset[i])
		{
			vector<int> neighs = adj[i];
			for(vector<int>::iterator it = neighs.begin(); it != neighs.end(); it++)
			{
				if(!sset[*it]) cout << i << " " << *it << endl;
			}
		}
	}
}

void solve()
{
	adj.clear();
	for(int i = 0; i < m; i++)
	{
		int from, to, cap; cin >> from >> to >> cap;
		capacity[from][to] = cap; capacity[to][from] = cap;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	// get the min cut
	max_flow();
	find_mincut();
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	s = 1, t = 2;
	cin >> n >> m;
	while(n != 0 && m != 0)
	{
		solve();
		cin >> n >> m;
	}
}