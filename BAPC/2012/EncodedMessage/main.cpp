#include <iostream>
#include <math.h>

using namespace std;

void solve()
{
	string line; cin >> line;
	int arrsize = sqrt(line.size());
	char grid[arrsize][arrsize];
	
	int index = 0;
	for(int y = 0; y < arrsize; y++)
		for(int x = 0; x < arrsize; x++)
		{
			grid[y][x] = line.at(index);
			index++;
		}
		
	string out = "";
	for(int x = arrsize - 1; x >= 0; x--)
	{
		for(int y = 0; y < arrsize; y++)
		{
			out.push_back(grid[y][x]);
		}
	}
	cout << out << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}