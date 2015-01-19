#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve()
{
	char m[1005][1005];
	int startX, startY, width, height;
	queue<int> fireq;
	cin >> width >> height;
	for(int y = 0; y < height; y++)
	{
		cin >> m[y];
		for(int x = 0; x < width; x++)
			if(m[y][x] == '@')
			{
				startX = x; startY = y;
			}
			else if(m[y][x] == '*') fireq.push(y * 10000 + x);
	}
	
	// bfs
	queue<int> q;
	int code = startY * 10000 + startX;
	map<int, int> steps;
	q.push(code);
	steps[code] = 0;
	while(!q.empty())
	{
		// expand the fire
		int firesize = fireq.size();
		for(int i = 0; i < firesize; i++)
		{
			int coords = fireq.front();
			fireq.pop();
			int fx = coords % 10000; coords /= 10000;
			int fy = coords;
			for(int j = 0; j < 4; j++)
			{
				int newfx = fx + dx[j];
				int newfy = fy + dy[j];
				if(newfx >= 0 && newfx < width && newfy >= 0 && newfy < height && m[newfy][newfx] == '.')
				{
					m[newfy][newfx] = '*';
					fireq.push(newfy * 10000 + newfx);
				}
			}
		}
		
		// let the player walk
		int qsize = q.size();
		for(int i = 0; i < qsize; i++)
		{
			int coords = q.front();
			q.pop();
			int st = steps[coords];
			int px = coords % 10000; coords /= 10000;
			int py = coords;
			
			if(px == 0 || py == 0 || px == width - 1 || py == height - 1)
			{
				cout << st + 1 << endl;
				return;
			}
			
			for(int j = 0; j < 4; j++)
			{
				int newX = px + dx[j];
				int newY = py + dy[j];
				int newCoords = newY * 10000 + newX;
				if(m[newY][newX] == '.' && steps.find(newCoords) == steps.end())
				{
					steps[newCoords] = st + 1;
					q.push(newCoords);
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}