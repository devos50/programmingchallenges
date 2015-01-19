#include <iostream>
#include <vector>

using namespace std;

int N, n;


int contains(vector<vector<char> > grid, vector<vector<char> > small, int N, int n)
{
	int ans = 0;
	for(int y = 0; y < N - n + 1; y++)
	{
		for(int x = 0; x < N - n + 1; x++)
		{
			bool isIn = true;
			for(int y1 = y; y1 < y + n; y1++)
			{
				for(int x1 = x; x1 < x + n; x1++)
				{
					if(grid[y1][x1] != small[y1 - y][x1 - x]) isIn = false;
				}
				if(!isIn) break;
			}
			if(isIn) ans++;
		}
	}
	return ans;
}

void solve(int N, int n)
{
	vector<vector<char > > grid;
	for(int y = 0; y < N; y++)
	{
		vector<char> vec;
		for(int x = 0; x < N; x++)
		{
			char z; cin >> z;
			vec.push_back(z);
		}
		grid.push_back(vec);
	}
			
	vector<vector<char > > small;
	for(int y = 0; y < n; y++)
	{
		vector<char> vec;
		for(int x = 0; x < n; x++)
		{
			char z; cin >> z;
			vec.push_back(z);
		}
		small.push_back(vec);
	}
	
	cout << contains(grid, small, N, n) << " ";
	
	for(int i = 0; i < 3; i++)
	{
		// place in vector
		vector<char> temp;
		for(int x = 0; x < n; x++)
			for(int y = n - 1; y >= 0; y--)
				temp.push_back(small[y][x]);
		
		small.clear();
		int c = 0;
		for(int y = 0; y < n; y++)
		{
			vector<char> vec;
			for(int x = 0; x < n; x++)
			{
				vec.push_back(temp[c]);
				// cout << temp[c];
				c++;
			}
			small.push_back(vec);
			// cout << endl;
		}
		
		cout << contains(grid, small, N, n);
		if(i != 2) cout << " ";
		
		// cout << endl;
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int N, n;
	while(true)
	{
		cin >> N >> n;
		if(N == 0 && n == 0) break;
		solve(N, n);
	}
}