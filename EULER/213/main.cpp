#include <iostream>
#include <cstdio>

#define N 30

using namespace std;

double grid[N][N];
double empty_grid[N][N];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
double avg;

void ring()
{
	double cpy[N][N];
	
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			cpy[y][x] = grid[y][x];
	
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
		{
			if(cpy[y][x] != 0.0)
			{
				// calculate adjacent tiles
				int tiles = 0;
				for(int i = 0; i < 4; i++)
				{
					int newx = x + dx[i];
					int newy = y + dy[i];
					if(newx >= N || newx < 0 || newy >= N || newy < 0) continue;
					tiles++;
				}
				
				double add = cpy[y][x] * (1.0 / (double)tiles);
				grid[y][x] = 0.0;
				for(int i = 0; i < 4; i++)
				{
					int newx = x + dx[i];
					int newy = y + dy[i];
					if(newx >= N || newx < 0 || newy >= N || newy < 0) continue;
					grid[newy][newx] += add;
				}
			}
		}
	
}

void print_grid()
{
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			printf("%.6f ", empty_grid[y][x]);
		}
		cout << endl;
	}
	cout << endl;
}

void reset_grid()
{
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			grid[y][x] = 0.0;
}

int main(int argc, char *argv[]) 
{
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			empty_grid[y][x] = 1.0;
	
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
		{
			reset_grid();
			grid[y][x] = 1.0;
				
			for(int i = 0; i < 50; i++)
				ring();
				
			// update empty_grid
			for(int y2 = 0; y2 < N; y2++)
				for(int x2 = 0; x2 < N; x2++)
				{
					empty_grid[y2][x2] *= 1.0 - grid[y2][x2];
				}
		}
		
	print_grid();
		
	double ans = 0.0;
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			ans += empty_grid[y][x];
	
	printf("%.6f", ans);
}