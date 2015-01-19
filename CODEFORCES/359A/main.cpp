#include <iostream>

using namespace std;

bool grid[55][55];
int n, m;

bool good_in_first_row()
{
	for(int x = 0; x < m; x++)
		if(grid[0][x]) return true;
	return false;
}

bool good_in_last_row()
{
	for(int x = 0; x < m; x++)
		if(grid[n - 1][x]) return true;
	return false;
}

bool good_in_first_col()
{
	for(int y = 0; y < n; y++)
		if(grid[y][0]) return true;
	return false;
}

bool good_in_last_col()
{
	for(int y = 0; y < n; y++)
		if(grid[y][m - 1]) return true;
	return false;
}

int main(int argc, char *argv[]) 
{
	cin >> n >> m;
	for(int y = 0; y < n; y++)
		for(int x = 0; x < m; x++)
			cin >> grid[y][x];
			
	if(good_in_first_row() || good_in_last_row() || good_in_first_col() || good_in_last_col()) cout << 2 << endl;
	else cout << 4 << endl;
}