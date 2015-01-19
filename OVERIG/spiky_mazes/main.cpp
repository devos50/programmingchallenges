#include <iostream>
#include <queue>
#include <map>

using namespace std;

char grid[45][45];
int width, height;
int jumps;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = {-1, 0, 1, 0 };

bool bfs(int x, int y)
{
	map<pair<int, int>, int> jleft;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	jleft[make_pair(x, y)] = 0;
	
	while(q.size() != 0)
	{
		pair<int, int> cur = q.front(); q.pop();
		// cout << "cur position: (" << cur.first << ", " << cur.second << ")" << endl;
		int curjumps = jleft[cur];
		
		if(grid[cur.second][cur.first] == 'x')
		{
			// cout << "cur jumps: " << curjumps << endl;
			if(2 * curjumps <= jumps) return true;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int newx = cur.first + dx[i];
			int newy = cur.second + dy[i];
			if(newx < 0 || newx >= width || newy < 0 || newy >= height) continue;
			if(jleft.find(make_pair(newx, newy)) != jleft.end()) continue;
			// cout << "new pos " <<newx << ", " << newy << endl;
			if(grid[newy][newx] == '.' || grid[newy][newx] == 'x')
			{
				q.push(make_pair(newx, newy));
				jleft[make_pair(newx, newy)] = curjumps;
			}
			else if(grid[newy][newx] == 's')
			{
				q.push(make_pair(newx, newy));
				jleft[make_pair(newx, newy)] = curjumps + 1;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) 
{
	cin >> height >> width >> jumps;
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			cin >> grid[y][x];
		}
	}
	
	bool can = false;
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			if(grid[y][x] == '@') 
				if(bfs(x, y)) { can = true; }
		}
	}
	
	if(!can) cout << "IMPOSSIBLE" << endl;
	else cout << "SUCCESS" << endl;
}