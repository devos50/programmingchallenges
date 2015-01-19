#include <iostream>

using namespace std;

char grid[105][105];
int h, w;
int docs;

bool bfs()
{
	
}

void solve()
{
	cin >> h >> w;
	for(int y = 0; y < h + 2; y++)
		for(int x = 0; x < w + 2; x++)
			grid[y][x] = '.';
			
	for(int y = 1; y < h + 1; y++)
		for(int x = 1; x < w + 1; x++)
			cin >> grid[y][x];
			
	for(int y = 0; y < h + 2; y++)
	{
		for(int x = 0; x < w + 2; x++)
		{
			cout << grid[y][x];
		}
		cout << endl;
	}
	cout << endl;
	
	string keys; cin >> keys;
	
	while(bfs()) ;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}