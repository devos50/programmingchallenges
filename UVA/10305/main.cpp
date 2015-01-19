#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, m;
vector<int> order;

void topo_order(map<int, set<int> > incoming)
{
	int toRemove = -1;
	for(map<int, set<int> >::iterator it = incoming.begin(); it != incoming.end(); it++)
	{
		if(it->second.size() == 0)
		{
			toRemove = it->first;
			break;
		}
	}
	
	if(toRemove == -1) return;
	order.push_back(toRemove);
	incoming.erase(toRemove);
				
	// remove incomings from toRemove
	for(map<int, set<int> >::iterator it = incoming.begin(); it != incoming.end(); it++)
	{
		if(it->first == toRemove) continue;
		it->second.erase(toRemove);
	}
	topo_order(incoming);
}

int main(int argc, char *argv[]) 
{
	cin >> n >> m;
	while(n != 0 || m != 0)
	{
		map<int, set<int> > incoming;
		order.clear();
		
		// init incoming
		for(int i = 1; i <= n; i++) incoming[i] = set<int>();
		
		for(int a = 0; a < m; a++)
		{
			int i, j; cin >> i >> j;
			incoming[j].insert(i);
		}
		
		topo_order(incoming);
		
		// print order
		for(int i = 0; i < order.size(); i++)
		{
			cout << order[i];
			if(i + 1 != order.size()) cout << " ";
		}
		cout << endl;
		
		cin >> n >> m;
	}
	
}