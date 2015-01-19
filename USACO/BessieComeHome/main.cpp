/*
 ID: mdmarti1
 PROG: comehome
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>

#define LINT 2000000000

using namespace std;

typedef struct Edge {
	char n1, n2;
	int weight;
} Edge;

map<char, vector<Edge> > adj;
set<char> nodes;
map<char, int> d;

struct compareDist
 {  
   bool operator()( char l, char r)  
   {  
       return d[l] > d[r];
   }  
 };

pair<char, int> shortest_path(char s)
{
	for(set<char>::iterator it = nodes.begin(); it != nodes.end(); it++)
		d[*it] = LINT;
	
	set<char> settled;
	priority_queue<char, vector<char>, compareDist> unsettled;
	unsettled.push(s);
	d[s] = 0;
	
	while(!unsettled.empty())
	{
		char u = unsettled.top(); unsettled.pop();
		settled.insert(u);
		
		// relaxatie van de buren
		for(vector<Edge>::iterator it = adj[u].begin(); it != adj[u].end(); it++)
		{
			Edge e = *it;
			char v = (e.n1 == u) ? e.n2 : e.n1;
			
			if(settled.find(v) != settled.end()) continue;
			if(d[v] > d[u] + e.weight)
			{
				d[v] = d[u] + e.weight;
				unsettled.push(v);
			}
		}
	}
	
	// find the min distance
	int min = LINT;
	int s_char = 'Z';
	for(map<char, int>::iterator it = d.begin(); it != d.end(); it++)
	{
		// cout << "node " << it->first << " distance " << it->second << endl;
		if(it->second < min && it->first >= 'A' && it->first < 'Z') { min = it->second; s_char = it->first; }
	}
	return make_pair(s_char, min);
}

int main()
{
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");
    
	int n; fin >> n;
	while(n--)
	{
		char n1, n2; int weight; fin >> n1 >> n2 >> weight;
		Edge e; e.n1 = n1; e.n2 = n2; e.weight = weight;
		adj[n1].push_back(e);
		adj[n2].push_back(e);
		
		nodes.insert(n1);
		nodes.insert(n2);
	}
	
	// dijkstra vanuit Z
	pair<char, int> ans = shortest_path('Z');
	fout << ans.first << " " << ans.second << endl;

    return 0;
}