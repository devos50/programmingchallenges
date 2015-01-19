#include <iostream>
#include <fstream>

using namespace std;

fstream fout("problem.out");
fstream fin("square_detector.txt");

void solve(int c)
{
	int n; fin >> n;
	int black = 0;
	bool foundLeft = false;
	pair<int, int> upleft;
	char grid[n][n];
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < n; x++)
		{
			fin >> grid[y][x];
			if(grid[y][x] == '#') black++;
			if(grid[y][x] == '#' && !foundLeft)
			{
				foundLeft = true;
				upleft = make_pair(x, y);
			}
		}
	}
	
	// find the width of the square
	// fout << "up left: " << upleft.first << ", " << upleft.second << endl;
	int width = 0;
	for(int x = upleft.first; x != n; x++)
	{
		if(grid[upleft.second][x] == '#') width++;
		else break;
	}
	
	if(upleft.second + width > n) { fout << "Case #" << c << ": " << "NO" << endl; return; }
	// check if everything is filled with squares
	for(int y = upleft.second; y < upleft.second + width; y++)
	{
		for(int x = upleft.first; x < upleft.first + width; x++)
		{
			if(grid[y][x] != '#') { fout << "Case #" << c << ": " << "NO" << endl; return; }
		}
	}
	
	if(width * width != black) { fout << "Case #" << c << ": " << "NO" << endl; return; }
	
	fout << "Case #" << c << ": " << "YES" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; fin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}