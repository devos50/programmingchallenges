#include <iostream>
#include <vector>

#define LINT 100000000

using namespace std;

typedef struct Edge {
	int from;
	int to;
	int time;
} Edge;

void solve()
{
	int n, m;
	cin >> n >> m;
	
	vector<Edge> edges;
	
	for(int i = 0; i < m; i++)
	{
		int x, y, time;
		cin >> x >> y >> time;
		Edge e; e.from = x; e.to = y; e.time = time;
		edges.push_back(e);
	}
	
	// bellman ford
	int distances[n];
	int prev[n];
	for(int i = 0; i < n; i++) distances[i] = LINT;
	distances[0] = 0;
	
	for(int i = 0; i < n; i++)
		for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
		{
			Edge cur = *it;
			if(distances[cur.from] + cur.time < distances[cur.to])
			{
				distances[cur.to] = distances[cur.from] + cur.time;
				prev[cur.to] = cur.from;
			}
		}
	
	for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		Edge cur = *it;
		if(distances[cur.from] + cur.time < distances[cur.to])
		{
			cout << "possible" << endl;
			return;
		}
	}
	cout << "not possible" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}