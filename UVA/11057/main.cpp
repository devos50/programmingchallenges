#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int prices[10005];

void solve(int n)
{
	for(int i = 0; i < n; i++) cin >> prices[i];
	int m; cin >> m;
	vector<pair<int, int> > solutions;
	
	int mindif = 100000000;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j) continue;
			if(prices[i] + prices[j] == m) { solutions.push_back(make_pair(prices[i], prices[j])); if(abs(prices[i] - prices[j]) < mindif) mindif = abs(prices[i] - prices[j]); }
		}
	}
	
	// find ans
	for(vector<pair<int, int> >::iterator it = solutions.begin(); it != solutions.end(); it++)
	{
		if(abs(it->first - it->second) == mindif)
		{
			int smallest = (it->first < it->second) ? it->first : it->second;
			int largest = (smallest == it->first) ? it->second : it->first;
			cout << "Peter should buy books whose prices are " << smallest << " and " << largest << "." << endl << endl;
			break;
		}
	}
}

int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n) solve(n);
}