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

using namespace std;

int adj[105][105];
int parent[105];
int size[105];
int n;

typedef struct Edge {
	int n1, n2;
	int weight;
} Edge;

vector<Edge> edges;

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

int main()
{
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");

	// clear arrays
	for(int i = 0; i < 105; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
    
	fin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			fin >> adj[i][j];
			if(i == j) continue;
			Edge e; e.n1 = i; e.n2 = j; e.weight = adj[i][j];
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
	fout << ans << endl;

    return 0;
}