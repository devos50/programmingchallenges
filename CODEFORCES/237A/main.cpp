#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int> visitors;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int h, m; cin >> h >> m;
		if(visitors.find(make_pair(h, m)) == visitors.end())
			visitors[make_pair(h, m)] = 1;
		else
			visitors[make_pair(h, m)]++;
	}
	
	int max_cash = 0;
	for(map<pair<int, int>, int>::iterator it = visitors.begin(); it != visitors.end(); it++)
	{
		if(it->second > max_cash) max_cash = it->second;
	}
	cout << max_cash << endl;
}