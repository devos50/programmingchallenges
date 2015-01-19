#include <iostream>
#include <set>

using namespace std;

int size[10005];
int parent[10005];

int dx[] = {  0,  1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1,  1,  0, -1 };

int find(int n) 
{
     if(parent[n] == n) return n;
     return parent[n] = find(parent[n]);
}

void merge(int x, int y) 
{
     int rx = find(x), ry = find(y);
     if(rx == ry) return;
     size[ry] += size[rx];
     parent[rx] = parent[ry];
}

void solve(int h, int w)
{
	char grid[h][w];
	for(int y = 0; y < h; y++)
		for(int x = 0; x < w; x++)
			cin >> grid[y][x];
			
	int elements = h * w;
	for(int i = 0; i < elements; i++)
	{
		size[i] = 1;
		parent[i] = i;
	}
	
	// iterate over the grid
	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			for(int i = 0; i < 8; i++)
			{
				int newx = x + dx[i];
				int newy = y + dy[i];
				if(newx == -1 || newx == w) continue;
				if(newy == -1 || newy == h) continue;
				
				if(grid[y][x] == '@' && grid[newy][newx] == '@')
				{
					merge(y * w + x, newy * w + newx);
				}
			}
		}
	}
	
	// count # sets
	set<int> s;
	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			if(grid[y][x] != '@') continue;
			s.insert(find(parent[y * w + x]));
		}
	}
	cout << s.size() << endl;
	
	// for(int i = 0; i < elements; i++) cout << find(parent[i]) << " ";
	// cout << endl;
}

int main(int argc, char *argv[]) 
{
	int h, w;
	while(cin >> h >> w)
	{
		if(h == 0 && w == 0) break;
		solve(h, w);
	}
}