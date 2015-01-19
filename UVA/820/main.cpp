#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, s, t;
map<int, vector<int> > adj;
int capacity[110][110];

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

void solve(int testcase)
{
	adj.clear();
	
	// reset capacities
	for(int y = 0; y < n+5; y++)
		for(int x = 0; x < n+5; x++)
			capacity[y][x] = 0;
	
	int c;
	cin >> s >> t >> c;
	for(int i = 0; i < c; i++)
	{
		int from, to, cap; cin >> from >> to >> cap;
		capacity[from][to] += cap; capacity[to][from] += cap;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	cout << "Network " << testcase << endl;
	cout << "The bandwidth is " << max_flow() << "." << endl << endl;
}

int main(int argc, char *argv[]) 
{
	cin >> n;
	int testcase = 1;
	while(n != 0)
	{
		solve(testcase);
		cin >> n;
		testcase++;
	}
}