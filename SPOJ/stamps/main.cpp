#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int &n1, const int &n2)
{
	return n1 > n2;
}

void solve(int test)
{
	int toborrow, friends; cin >> toborrow >> friends;
	vector<int> stamps;
	for(int i = 0; i < friends; i++) { int s; cin >> s; stamps.push_back(s); }
	sort(stamps.begin(), stamps.end(), compare);
	
	int total = 0;
	int needed_friends = 0;
	for(int i = 0; i < stamps.size(); i++)
	{
		total += stamps[i];
		needed_friends++;
		if(total >= toborrow) break;
	}
	
	cout << "Scenario #" << test << ":" << endl;
	if(total < toborrow) cout << "impossible" << endl << endl; // hier gaat het mis
	else cout << needed_friends << endl << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}