/*
 ID: mdmarti1
 PROG: maze1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define LINT 2000000

using namespace std;

int height, width;
char grid[205][100];
int steps[205][100];
vector<pair<int, int> > exits;

int dx[4] = { 0, 2, 0, -2 };
int dy[4] = { -2, 0, 2, 0 };
int dxs[4] = { 0, 1, 0, -1 };
int dys[4] = { -1, 0, 1, 0 };

void bfs(pair<int, int> start)
{
	cout << "start: " << start.first << ", " << start.second << endl;
	queue<pair<int, int> > q;
	q.push(start);
	map<pair<int, int>, int> seen;
	seen[start] = 1;
	steps[start.second][start.first] = 1;
	while(q.size() != 0)
	{
		pair<int, int> cur = q.front(); q.pop();
		int cursteps = seen[cur];
		// cout << "cur position: " << cur.first << ", " << cur.second << ", steps: " << cursteps << endl;
		
		for(int i = 0; i < 4; i++)
		{
			int newx = cur.first + dx[i];
			int newy = cur.second + dy[i];
			int newxs = cur.first + dxs[i];
			int newys = cur.second + dys[i];
			
			if(grid[newy][newx] != ' ' || newx >= width || newy >= height || newx <= 0 || newy <= 0 || grid[newys][newxs] == '|' || grid[newys][newxs] == '-') continue;
			if(seen.find(make_pair(newx, newy)) != seen.end()) continue;
			
			seen[make_pair(newx, newy)] = cursteps + 1;
			steps[newy][newx] = min(steps[newy][newx], cursteps + 1);
			q.push(make_pair(newx, newy));
		}
	}
}

int main()
{
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    
	fin >> width >> height;
	width = width * 2 + 1;
	height = height * 2 + 1;
	cout << "width: " << width << ", height: " << height << endl;
	
	string s; getline(fin, s);
	
	for(int y = 0; y < height; y++)
	{
		string l; getline(fin, l);
		for(int x = 0; x < width; x++)
		{
			grid[y][x] = l[x];
			if(grid[y][x] == ' ' && (y == 0 || x == 0 || y == height - 1 || x == width - 1)) exits.push_back(make_pair(x, y));
		}
	}
	
	// clear steps arr
	for(int y = 0; y < 205; y++)
		for(int x = 0; x < 100; x++)
			steps[y][x] = LINT;
	
	// bfs
	for(vector<pair<int, int> >::iterator it = exits.begin(); it != exits.end(); it++)
	{
		if(it->first == 0) bfs(make_pair(it->first + 1, it->second));
		else if(it->first == width - 1) bfs(make_pair(it->first - 1, it->second));
		else if(it->second == 0) bfs(make_pair(it->first, it->second + 1));
		else if(it->second == height - 1) bfs(make_pair(it->first, it->second - 1));
	}
	/*
	// temp! print steps
	// cout << "steps at (5,1): " << steps[1][5] << endl;
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			if(steps[y][x] == LINT) cout << " ";
			else cout << steps[y][x];
		}
		cout << endl;
	}
	*/
	// find ans
	int max = -1;
	for(int y = 0; y < 205; y++)
		for(int x = 0; x < 100; x++)
			if(steps[y][x] > max && steps[y][x] != LINT) max = steps[y][x];
			
	fout << max << endl;

    return 0;
}