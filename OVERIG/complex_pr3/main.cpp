#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef struct Edge {
	int from, to;
	bool in_graph;
} Edge;

int n, m; // n = knopen, m = kanten
set<Edge *> edges; // set of edges
map<int, vector<Edge *> > adj;

int main(int argc, char *argv[]) 
{
	// lees alles in
	fstream fin("graph2.in");
	fin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int from, to; fin >> from >> to;
		Edge *e = new Edge();
		e->from = from; e->to = to; e->in_graph = true;
		edges.insert(e);
		adj[from].push_back(e);
		adj[to].push_back(e);
	}
	
	// pas algoritme toe
	set<Edge *> aprime;
	
	for(int i = 0; i < n; i++)
	{
		// bepaal de in-set en out-set van knoop i (a)
		set<Edge *> inset, outset;
		for(vector<Edge *>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
		{
			Edge *cur = *it;
			if(!cur->in_graph) continue;
			if(cur->from == i) outset.insert(cur);
			else inset.insert(cur);
		}
		
		// (b)
		if(inset.size() > outset.size())
		{
			// (b) I
			for(set<Edge *>::iterator it = inset.begin(); it != inset.end(); it++)
			{
				aprime.insert(*it);
			}
		}
		else
		{
			// (c) I
			for(set<Edge *>::iterator it = outset.begin(); it != outset.end(); it++)
			{
				aprime.insert(*it);
			}
		}
		
		// (a)/(b) II
		for(vector<Edge *>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
		{
			(*it)->in_graph = false;
		}
	}
	cout << edges.size() - aprime.size() << " kanten niet op de oplossing:" << endl;
	for(set<Edge *>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		if(aprime.find(*it) == aprime.end())
			cout << (*it)->from << " -> " << (*it)->to << endl;
	}
}