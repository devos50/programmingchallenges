#include <iostream>

using namespace std;

int dx[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int height, width;
int t = 1;
char map[105][105];

int countbombs(int x, int y)
{
	int bombs = 0;
	for(int i = 0; i < 8; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];
		if(newX < 0 || newX >= width || newY < 0 || newY >= height) continue;
		if(map[newY][newX] == '*') bombs++;
	}
	return bombs;
}

void solve()
{
	for(int y = 0; y < height; y++)
		cin >> map[y];
	
	for(int y = 0; y < height; y++)
		for(int x = 0; x < width; x++)
		{
			if(map[y][x] == '*') continue;
			map[y][x] = (char)('0' + countbombs(x, y));
		}
		
	cout << "Field #" << t << ":" << endl;
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			cout << map[y][x];
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) 
{
	bool firsttime = true;
	while(true)
	{
		cin >> height; cin >> width;
		if(height == 0 && width == 0) break;
		if(!firsttime) cout << endl;
		solve();
		t++;
		firsttime = false;
	}
}