/*
 ID: mdmarti1
 PROG: butter
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set>

#define LINT 2000000000

using namespace std;

typedef struct Edge {
	int n1, n2;
	int weight;
} Edge;

int N, P, C;
map<int, vector<Edge> > adj;
vector<int> pasts;
int d[1455];

struct order2 
{
 	bool operator() (const pair<int, int> &a, const pair<int, int> &b) 
	{
    	if (a.second != b.second) return a.second < b.second;
    
		return a.first < b.first;
	}
};

int path_sum(int s)
{
	for(int i = 1; i <= 1450; i++)
		d[i] = LINT;
	
	set<int> settled;
	set<pair<int, int>,order2> unsettled;
	unsettled.insert(make_pair(s, 0));
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
			
			// cout << "u: " << u << ", v: " << v << endl;
			
			if(settled.find(v) != settled.end()) continue;
			if(d[v] > d[u] + e.weight)
			{
				d[v] = d[u] + e.weight;
				unsettled.push(v);
			}
		}
	}
	
	int sum = 0;
	for(vector<int>::iterator it = pasts.begin(); it != pasts.end(); it++)
	{
		sum += d[*it];
	}
	return sum;
}

int main()
{
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
    
	fin >> N >> P >> C;
	for(int i = 0; i < N; i++)
	{
		int n; fin >> n;
		pasts.push_back(n);
	}
	
	for(int i = 0; i < C; i++)
	{
		Edge e; fin >> e.n1 >> e.n2 >> e.weight;
		adj[e.n1].push_back(e);
		adj[e.n2].push_back(e);
	}
	
	int minsum = LINT;
	for(int i = 1; i <= P; i++)
	{
		int sum = path_sum(i);
		// cout << "sum from past " << i << ": " << path_sum(i) << endl;
		if(sum < minsum) minsum = sum;
	}
	fout << minsum << endl;

    return 0;
}