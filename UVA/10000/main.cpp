#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, vector<int> > adjList;

int removeMin(set<int> unsettled, map<int, int> shortestDistances)
{
	int min = 1000000000;
	char minchar;
	for(set<int>::iterator it = unsettled.begin(); it != unsettled.end(); it++)
	{
		if(shortestDistances[*it] < min)
		{
			min = shortestDistances[*it];
			minchar = *it;
		}
	}
	return minchar;
}

void dijkstra(int start, int testcase)
{
	set<int> unsettled;
	map<int, int> shortestDistances;
	
	// fill shortestDistances
	for(map<int, vector<int> >::iterator it = adjList.begin(); it != adjList.end(); it++)
		shortestDistances[it->first] = -1000000000;
	
	unsettled.insert(start);
	shortestDistances[start] = 0;
	
	while(unsettled.size() != 0)
	{
		// remove the min dist from unsettled
		int cur = removeMin(unsettled, shortestDistances);
		unsettled.erase(unsettled.find(cur));
		
		// relaxation of cur
		vector<int> adj = adjList[cur];
		for(vector<int>::iterator it = adj.begin(); it != adj.end(); it++)
		{
			if(shortestDistances[*it] < shortestDistances[cur] + 1)
			{
				shortestDistances[*it] = shortestDistances[cur] + 1;
				unsettled.insert(*it);
			}
		}
	}
	
	// TODO here
	int max = -1;
	int maxind = -1;
	for(map<int, int>::iterator it = shortestDistances.begin(); it != shortestDistances.end(); it++)
	{
		if(it->second > max)
		{
			max = it->second;
			maxind = it->first;
		}
	}
	cout << "Case " << testcase << ": The longest path from " << start << " has length " << max << ", finishing at " << maxind << "." << endl << endl;
}

void solve(int nodes, int testcase)
{
	adjList.clear();
	int start; cin >> start;
	int p, q;
	while(true)
	{
		cin >> p >> q;
		if(p == 0 && q == 0) break;
		adjList[p].push_back(q);
	}
	dijkstra(start, testcase);
}

int main(int argc, char *argv[]) 
{
	int nodes;
	int counter = 1;
	while(true)
	{
		cin >> nodes;
		if(nodes == 0) break;
		solve(nodes, counter);
		counter++;
	}
}