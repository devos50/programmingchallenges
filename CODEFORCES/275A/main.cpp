#include <iostream>

using namespace std;

// int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
// int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main(int argc, char *argv[]) 
{
	bool grid[3][3];
	for(int y = 0; y < 3; y++)
		for(int x = 0; x < 3; x++)
			grid[y][x] = true;
	
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			int presses;
			cin >> presses;
			for(int i = 0; i < presses; i++)
			{
				grid[y][x] = !grid[y][x];
				for(int j = 0; j < 4; j++)
				{
					int newx = x + dx[j];
					int newy = y + dy[j];
					if(newx < 0 || newx > 2 || newy < 0 || newy > 2) continue;
					grid[newy][newx] = !grid[newy][newx];
				}
			}
		}
	}
	
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			cout << grid[y][x];
		}
		cout << endl;
	}
}