#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

// input:
// regel 1: aantal test cases
// regel 2: aantal nodes + aantal edges
// regel 3: s en t
// daarna m regels met op iedere regel from, to en capacity

using namespace std;

int s, t;
int m, n;
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
	
	if(from[t] == -1) return 0;
	
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
	return path_cap;
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

void solve()
{
	cin >> n >> m;
	cin >> s >> t;
	for(int i = 0; i < m; i++)
	{
		int from, to, cap; cin >> from >> to >> cap;
		capacity[from][to] = cap; capacity[to][from] = 0;
		adj[from].push_back(to);
	}
	
	cout << max_flow();
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}