#include <iostream>
#include <vector>
#include <map>
#include <cassert>

#define IMAX 1E9

using namespace std;

typedef struct Edge {
	int from;
	int to;
	int weight;
} Edge;

vector<Edge> edges;
int dist[105][105];
int n, m, l;

void fw()
{
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			dist[i][j] = IMAX;
			
	for(int i = 0; i < n; i++) dist[i][i] = 0;
	for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		dist[it->from][it->to] = min(it->weight, dist[it->from][it->to]);
		dist[it->to][it->from] = min(it->weight, dist[it->from][it->to]);
	}
	
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j];
}

long long getcosts()
{
	long long c = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(dist[i][j] != IMAX) c += dist[i][j];
			else c += l;
		}
	return c;
}

void solve()
{
	edges.clear();
	
	for(int i = 0; i < m; i++)
	{
		int a, b, s; cin >> a >> b >> s;
		a--; b--;
		Edge e; e.from = a; e.to = b; e.weight = s; edges.push_back(e);
	}
	
	fw();
	cout << getcosts();
	
	// calculate costs before
	long long maxc = -1;
	
	for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		int oldweight = it->weight;
		it->weight = IMAX;
		
		fw();
		long long newcosts = getcosts();
		if(newcosts > maxc) maxc = newcosts;
		
		it->weight = oldweight;
	}
	cout << " " << maxc << endl;
}

int main(int argc, char *argv[]) 
{
	while(cin >> n >> m >> l)
		solve();
}