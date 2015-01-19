#include <iostream>

using namespace std;

void solve()
{
	int r, c; cin >> r >> c;
	char grid[r][c];
	for(int y = 0; y < r; y++)
		for(int x = 0; x < c; x++)
			cin >> grid[y][x];
		
	int candies = 0;
	for(int y = 0; y < r; y++)
	{
		for(int x = 0; x < c; x++)
		{
			if(grid[y][x] == 'o') // check if there's a candy
			{
				if(x != 0 && x != c - 1) // check for a candy horizontal
					if(grid[y][x-1] == '>' && grid[y][x+1] == '<') candies++;
					
				if(y != 0 && y != r - 1) // check for a candy vertical
					if(grid[y-1][x] == 'v' && grid[y+1][x] == '^') candies++;
			}
		}
	}
	cout << candies << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}