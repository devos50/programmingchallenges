#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

#define LINT 2000000000

using namespace std;

typedef struct Edge {
	int n1, n2;
	int weight;
} Edge;

map<int, vector<Edge> > adj;
int d[20005];
set<int> nodes;
int n, m, s, t;

struct compareDist
 {  
   bool operator()( int l, int r)  
   {  
       return d[l] > d[r];
   }  
 };

int shortest_path()
{
	for(int i = 0; i < n; i++) d[i] = LINT;
	
	set<int> settled;
	priority_queue<int, vector<int>, compareDist> unsettled;
	unsettled.push(s);
	d[s] = 0;
	
	while(!unsettled.empty())
	{
		int u = unsettled.top(); unsettled.pop();
		settled.insert(u);
		
		// relaxatie van de buren
		for(vector<Edge>::iterator it = adj[u].begin(); it != adj[u].end(); it++)
		{
			Edge e = *it;
			int v = (e.n1 == u) ? e.n2 : e.n1;
			
			if(settled.find(v) != settled.end()) continue;
			if(d[v] > d[u] + e.weight)
			{
				d[v] = d[u] + e.weight;
				unsettled.push(v);
			}
		}
	}
	
	return d[t];
}

void solve(int c)
{
	adj.clear();
	nodes.clear();
	
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++)
	{
		int n1, n2, w; cin >> n1 >> n2 >> w;
		Edge e; e.n1 = n1; e.n2 = n2; e.weight = w;
		adj[n1].push_back(e);
		adj[n2].push_back(e);
				
		nodes.insert(n1);
		nodes.insert(n2);
	}
	
	int dist = shortest_path();
	if(dist == LINT) cout << "Case #" << c << ": unreachable" << endl;
	else cout << "Case #" << c << ": " << shortest_path() << endl;
	
	
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}