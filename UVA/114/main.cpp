#include <iostream>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

typedef struct Ball
{
	int x;
	int y;
	int lifetime;
	int direction;
	int points;
	
	void turn()
	{
		if(direction == 0) direction = 3;
		else direction--;
	}
	
} Ball;

typedef struct Bumper
{
	int value;
	int cost;
} Bumper;

int main(int argc, char *argv[]) 
{
	int height, width; cin >> height >> width;
	int grid[height][width];
	for(int y = 0; y < height; y++)
		for(int x = 0; x < width; x++)
			grid[y][x] = 0;
	int wallcost; cin >> wallcost;
	int numbumpers; cin >> numbumpers;
	
	// read bumpers
	Bumper bumpers[numbumpers+5];
	for(int i = 1; i <= numbumpers; i++)
	{
		Bumper b;
		int bx, by; cin >> bx >> by;
		bx--; by--;
		grid[by][bx] = i;
		cin >> b.value >> b.cost;
		bumpers[i] = b;
	}
	
	Ball b;
	int pointsum = 0;
	while(cin >> b.x && cin >> b.y && cin >> b.direction && cin >> b.lifetime)
	{
		b.points = 0;
		b.x--; b.y--;
		while(b.lifetime > 1)
		{
			int newdx = b.x + dx[b.direction];
			int newdy = b.y + dy[b.direction];
			
			if(newdx == 0 || newdx == width - 1 || newdy == 0 || newdy == height - 1) // wall hit
			{
				b.lifetime -= wallcost;
				b.turn();
			}
			else if(grid[newdy][newdx] != 0) // bumper hit
			{
				Bumper bump = bumpers[grid[newdy][newdx]];
				b.points += bump.value;
				b.lifetime -= bump.cost;
				b.turn();
			}
			else
			{
				b.x = newdx;
				b.y = newdy;
			}
			b.lifetime--;
		}
		pointsum += b.points;
		cout << b.points << endl;
	}
	cout << pointsum << endl;
}