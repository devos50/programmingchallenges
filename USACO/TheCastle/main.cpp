/*
 ID: mdmarti1
 PROG: castle
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct Result {
	int x;
	int y;
	int dir;
} Result;

int parent[2505];
int size[2505];
int maxsize = -1;
int m, n;
vector<Result> results;

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

vector<bool> getWallVec(int n)
{
	vector<bool> vec;
	for(int i = 0; i < 4; i++)
	{
		vec.push_back(n % 2 != 0);
		n /= 2;
	}
	
	return vec;
}

void findNewSize(int d1, int d2, int x, int y, int dir)
{
	int newsize = size[find(d1)] + size[find(d2)];
	if(newsize >= maxsize) 
	{
		if(newsize > maxsize) results.clear();
		maxsize = newsize;
		Result r; r.x = x; r.y = y; r.dir = dir;
		if(dir == 1 || dir == 2) results.push_back(r);
	}
}

bool compare(const Result &r1, const Result &r2)
{
	if(r1.x < r2.x) return true;
	else if(r1.x == r2.x && r1.y > r2.y) return true;
	else if(r1.x == r2.x && r1.y == r2.y && r1.dir == 1 && r2.dir == 2) return true;
	return false;
}

int main()
{
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
	fin >> m >> n;
	vector<int> squares;
	for(int i = 0; i < m * n; i++)
	{
		int s; fin >> s;
		squares.push_back(s);
	}
	
	// make sets of union-find datastructures
	for(int i = 0; i < n * m; i++) parent[i] = i, size[i] = 1;
	
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			int a = squares[y * m + x];
			vector<bool> walls = getWallVec(a);
			
			// check west tile
			if(x != 0 && !walls[0]) merge(y * m + x, y * m + x - 1);
			// check north tile
			if(y != 0 && !walls[1]) merge(y * m + x, (y - 1) * m + x);
			// check east tile
			if(x != m - 1 && !walls[2]) merge(y * m + x, y * m + x + 1);
			// check south tile
			if(x != n - 1 && !walls[3]) merge(y * m + x, (y + 1) * m + x);
		}
	}
	
	// find the number of rooms
	int rooms = 0;
	for(int i = 0; i < m * n; i++)
		if(parent[i] == i) rooms++;
	fout << rooms << endl;
	
	// find the biggest set
	int max = -1;
	for(int i = 0; i < m * n; i++)
		if(size[i] > max) max = size[i];
	fout << max << endl;
	
	// find the size of the largest room if a wall is removed
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			int a = squares[y * m + x];
			vector<bool> walls = getWallVec(a);
			
			// check west tile
			if(x != 0 && walls[0] && find(y * m + x) != find(y * m + x - 1))
			{
				findNewSize(y * m + x, y * m + x - 1, x, y, 0);
			}
			// check north tile
			if(y != 0 && walls[1] && find(y * m + x) != find((y - 1) * m + x))
			{
				findNewSize(y * m + x, (y - 1) * m + x, x, y, 1);
			}
			// check east tile
			if(x != m - 1 && walls[2] && find(y * m + x) != find(y * m + x + 1))
			{
				findNewSize(y * m + x, y * m + x + 1, x, y, 2);
			}
			// check south tile
			if(x != n - 1 && !walls[3] && find(y * m + x) != find((y + 1) * m + x))
			{
				findNewSize(y * m + x, (y + 1) * m + x, x, y, 3);
			}
		}
	}
	fout << maxsize << endl;
	
	// find the result
	sort(results.begin(), results.end(), compare);
	
	for(vector<Result>::iterator it = results.begin(); it != results.end(); it++)
	{
		Result r = *it;
		cout << "result x: " << r.x << ", y: " << r.y << ", dir: " << r.dir << endl;
	}
	
	fout << results[0].y + 1 << " " << results[0].x + 1 << " ";
	if(results[0].dir == 1) fout << "N" << endl;
	else fout << "E" << endl;

    return 0;
}