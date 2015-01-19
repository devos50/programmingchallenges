#include <iostream>
#include <map>
#include <cmath>
#include <cstdlib>

using namespace std;

void solve()
{
	map<int, pair<int, int> > car_pos;
	int h, l; cin >> h >> l;
	int cars = 0;
	int building[h][l];
	for(int i = 0; i < h; i++)
		for(int j = 0; j < l; j++)
		{
			cin >> building[i][j];
			if(building[i][j] != -1)
			{
				pair<int, int> curcar = make_pair(j, i);
				car_pos[building[i][j]] = curcar;
			}
			if(building[i][j] > cars) cars = building[i][j];
		}
			
	int elposx = 0, elposy = 0;
	int totaltime = 0;
	for(int i = 1; i <= cars; i++)
	{
		int carx = car_pos[i].first;
		int cary = car_pos[i].second;
		
		// cout << "car " << i << ": " << carx << ", " << cary << endl;
		
		// bring elevator to right floor
		totaltime += abs(cary) * 10;
		elposy = cary;
		
		// go left or right
		totaltime += min(abs(carx - elposx), l - abs(carx - elposx)) * 5;
		elposx = carx;
		
		// go down
		totaltime += elposy * 10;
		elposy = 0;
	}
	cout << totaltime << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}