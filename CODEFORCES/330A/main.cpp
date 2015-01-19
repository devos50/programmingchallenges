#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int r, c; cin >> r >> c;
	bool grid[r][c];
	bool eaten[r][c];
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			char c; cin >> c;
			if(c == '.') grid[i][j] = false;
			else grid[i][j] = true;
		}
	}
	
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			eaten[i][j] = false;
			
	int ans = 0;
			
	// eat all rows
	for(int i = 0; i < r; i++)
	{
		// check if we can eat it
		bool can = true;
		for(int j = 0; j < c; j++)
		{
			if(grid[i][j]) can = false;
		}
		
		if(can)
		{
			for(int j = 0; j < c; j++)
			{
				if(!eaten[i][j]) ans++;
				eaten[i][j] = true;
			}
		}
	}
	
	// eat all rows
		for(int i = 0; i < c; i++)
		{
			// check if we can eat it
			bool can = true;
			for(int j = 0; j < r; j++)
			{
				if(grid[j][i]) can = false;
			}
			
			if(can)
			{
				for(int j = 0; j < r; j++)
				{
					if(!eaten[j][i]) ans++;
					eaten[j][i] = true;
				}
			}
		}
	cout << ans << endl;
}