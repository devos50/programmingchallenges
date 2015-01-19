#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	int p[m];
	vector<vector<int> > rooms;
	for(int i = 0; i < m; i++)
		cin >> p[i];
		
	for(int i = 0; i < n; i++)
	{
		int c; cin >> c;
		vector<int> bottles;
		for(int j = 0; j < c; j++)
		{
			int in; cin >> in;
			bottles.push_back(in);
		}
		sort(bottles.begin(), bottles.end());
		rooms.push_back(bottles);
	}
	
	// visit rooms
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		if(rooms[p[i]].size() == 0) continue;
		ans += rooms[p[i]].back();
		rooms[p[i]].pop_back();
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}