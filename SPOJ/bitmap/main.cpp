#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void solve()
{
	int height, width; cin >> height >> width;
	char grid[height][width];
	for(int i = 0; i < height; i++)
		for(int j = 0; j < width; j++)
			cin >> grid[i][j];
		
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			queue<int> q;
			int code = y * 130 + x;
			q.push(code);
			
			int steps[18000];
			for(int i = 0; i < 18000; i++) steps[i] = -1;
			steps[code] = 0;
			while(q.size() != 0)
			{
				int current = q.front(); q.pop();
				int cursteps = steps[current];
				int curx = current % 130; current /= 130;
				int cury = current;
				
				if(grid[cury][curx] == '1')
				{
					cout << cursteps;
					if(x != width - 1) cout << " ";
					break;
				}
				
				// add neighbours
				for(int i = 0; i < 4; i++)
				{
					int newx = curx + dx[i];
					int newy = cury + dy[i];
					int newcode = newy * 130 + newx;
					if(newx >= 0 && newx < width && newy >= 0 && newy < height && steps[newcode] == -1)
					{
						steps[newcode] = cursteps + 1;
						q.push(newcode);
					}
				}
			}
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}