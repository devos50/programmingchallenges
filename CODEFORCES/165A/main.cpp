#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int ans = 0;
	vector<pair<int, int> > points;
	for(int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	
	for(vector<pair<int, int> >::iterator it = points.begin(); it != points.end(); it++)
	{
		pair<int, int> curp = *it;
		bool r = false, le = false, u = false, lo = false;
		for(vector<pair<int, int> >::iterator it2 = points.begin(); it2 != points.end(); it2++)
		{
			pair<int, int> curp2 = *it2;
			if(curp == curp2) continue;
			if(curp2.first > curp.first && curp2.second == curp.second) r = true;
			if(curp2.first < curp.first && curp2.second == curp.second) le = true;
			if(curp2.first == curp.first && curp2.second < curp.second) lo = true;
			if(curp2.first == curp.first && curp2.second > curp.second) u = true;
		}
		if(r && le && u && lo) ans++;
	}
	cout << ans << endl;
}