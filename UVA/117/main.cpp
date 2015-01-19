#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

map<char, vector<char> > adjList;
int distances[30][30];

char removeMin(set<char> unsettled, map<char, int> shortestDistances)
{
	int min = 1000000000;
	char minchar;
	for(set<char>::iterator it = unsettled.begin(); it != unsettled.end(); it++)
	{
		if(shortestDistances[*it] < min)
		{
			min = shortestDistances[*it];
			minchar = *it;
		}
	}
	return minchar;
}

int dijkstra(char start, char end)
{
	set<char> unsettled;
	map<char, int> shortestDistances;
	
	// fill shortestDistances
	for(map<char, vector<char> >::iterator it = adjList.begin(); it != adjList.end(); it++)
		shortestDistances[it->first] = 1000000000;
	
	unsettled.insert(start);
	shortestDistances[start] = 0;
	
	while(unsettled.size() != 0)
	{
		// remove the min dist from unsettled
		char cur = removeMin(unsettled, shortestDistances);
		unsettled.erase(unsettled.find(cur));
		
		// relaxation of cur
		vector<char> adj = adjList[cur];
		for(vector<char>::iterator it = adj.begin(); it != adj.end(); it++)
		{
			if(shortestDistances[*it] > shortestDistances[cur] + distances[*it - 'a'][cur - 'a'])
			{
				shortestDistances[*it] = shortestDistances[cur] + distances[*it - 'a'][cur - 'a'];
				unsettled.insert(*it);
			}
		}
	}
	
	return shortestDistances[end];
}

void solve(string street)
{
	adjList.clear();
	for(int y = 0; y < 30; y++)
		for(int x = 0; x < 30; x++)
			distances[y][x] = -1;
	
	int sum = 0;
	
	while(street.compare("deadend"))
	{
		char begin = street.at(0);
		char end = street.at(street.size() - 1);
		distances[begin - 'a'][end - 'a'] = street.size();
		distances[end - 'a'][begin - 'a'] = street.size();
		adjList[begin].push_back(end);
		adjList[end].push_back(begin);
		sum += street.size();
		cin >> street;
	}
	
	bool allEven = true;
	vector<char> oddnodes;
	for(map<char, vector<char> >::iterator it = adjList.begin(); it != adjList.end(); it++)
	{
		vector<char> v = it->second;
		if(v.size() % 2 != 0)
		{
			allEven = false;
			oddnodes.push_back(it->first);
		} 
	}
	
	if(allEven) // result is sum of lenghts of the streets
	{
		cout << sum << endl;
	}
	else // find shortest path between the two odd nodes
	{
		char n1 = oddnodes[0];
		char n2 = oddnodes[1];
		int shortestDist = dijkstra(n1, n2);
		cout << sum + shortestDist << endl;
	}
}

int main(int argc, char *argv[]) 
{
	string street;
	while(cin >> street) solve(street);
}