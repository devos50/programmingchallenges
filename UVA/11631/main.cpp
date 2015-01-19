/*
 ID: mdmarti1
 PROG: agrinet
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<int> > adj;
int parent[200005];
int size[200005];

typedef struct Edge {
	int n1, n2;
	int weight;
} Edge;

vector<Edge> edges;
int n, m;

bool comp(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

int find(int n)
{
	if(parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int x, int y)
{
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	size[ry] += size[rx];
	parent[rx] = parent[ry];
}

void solve()
{
	// clear arrays
	for(int i = 0; i < 200005; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
	
	int total = 0;
	for(int i = 0; i < n; i++)
	{
		int n1, n2, w; cin >> n1 >> n2 >> w;
		total += w;
		Edge e; e.n1 = n1; e.n2 = n2; e.weight = w;
		edges.push_back(e);
	}
			
	// sort edges
	int ans = 0;
	sort(edges.begin(), edges.end(), comp);
	for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		int n1 = it->n1; int n2 = it->n2;
		if(find(n1) != find(n2))
		{
			// cout << "n1: " << n1 << ", n2: " << n2 << ", weight: " << it->weight << endl;
			ans += it->weight;
			merge(n1, n2);
		}
	}
	cout << total - ans << endl;
}

int main()
{
	while(true)
	{
		cin >> m >> n;
		if(n == 0 && m == 0) break;
		solve();
	}

    return 0;
}