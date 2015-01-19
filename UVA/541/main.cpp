#include <iostream>

using namespace std;

void solve(int n)
{
	int grid[n][n];
	for(int y = 0; y < n; y++)
		for(int x = 0; x < n; x++)
			cin >> grid[y][x];
	
	// row sums
	int rsum[n];
	for(int y = 0; y < n; y++)
	{
		int sum = 0;
		for(int x = 0; x < n; x++)
			sum += grid[y][x];
		rsum[y] = sum;
	}
	
	// row sums
	int csum[n];
	for(int x = 0; x < n; x++)
	{
		int sum = 0;
		for(int y = 0; y < n; y++)
			sum += grid[y][x];
		csum[x] = sum;
	}
	
	// check if all sums are even
	bool ok = true;
	for(int i = 0; i < n; i++)
		if(rsum[i] % 2 == 1 || csum[i] % 2 == 1) { ok = false; break; }
	
	if(ok) { cout << "OK" << endl; return; }
	
	// try to change every bit
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < n; x++)
		{
			if(grid[y][x] == 1 && (rsum[y] - 1) % 2 == 0 && (csum[x] - 1) % 2 == 0) // change to 0
			{
				// check if matrix is now good
				bool ok = true;
				for(int i = 0; i < n; i++)
				{
					if(i == x || i == y) continue;
					if(rsum[i] % 2 == 1 || csum[i] % 2 == 1) { ok = false; break; }
				}
				if(!ok) continue;
				
				cout << "Change bit (" << y + 1 << "," << x + 1 << ")" << endl;
				return;
			}
			if(grid[y][x] == 0 && (rsum[y] + 1) % 2 == 0 && (csum[x] + 1) % 2 == 0) // change to 1
			{
				// check if matrix is now good
				bool ok = true;
				for(int i = 0; i < n; i++)
				{
					if(i == x || i == y) continue;
					if(rsum[i] % 2 == 1 || csum[i] % 2 == 1) { ok = false; break; }
				}
				if(!ok) continue;
				
				cout << "Change bit (" << y + 1 << "," << x + 1 << ")" << endl;
				return;
			}
		}
	}
	cout << "Corrupt" << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}
}