#include <iostream>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int s, t;
int n;
map<int, vector<int> > adj;
int capacity[2005][2005];

typedef struct Node {
	int demand;
	Node next;
} Node;

/*
int find_path()
{
	// bfs
	queue<int> q;
	q.push(s);
	bool visited[n+5]; for(int i = 0; i < n + 5; i++) visited[i] = false;
	visited[s] = true;
	int from[n+5]; for(int i = 0; i < n + 5; i++) from[i] = -1;
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
	return path_cap;
}

int max_flow() {
	int result = 0;
	while(true)
	{
		int path_capacity = find_path();
		if(path_capacity == 0) break;
		else result += path_capacity;
	}
	return result;
}
*/

void bfs()
{
	queue<Node> q;
}

int main(int argc, char *argv[]) 
{
	cin >> n;
	s = 0; t = 2004;
	for(int i = 0; i < n; i++)
	{
		int p, r, c; cin >> p >> r >> c;
		
	}
}
