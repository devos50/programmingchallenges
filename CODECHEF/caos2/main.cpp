#include <iostream>

using namespace std;

char grid[505][505];

int l[505][505];
int r[505][505];
int t[505][505];
int b[505][505];

int primes_below[505];
int rc, c;

void clear_arrs()
{
	for(int y = 0; y < 505; y++)
		for(int x = 0; x < 505; x++)
		{
			l[y][x] = 0;
			r[y][x] = 0;
			t[y][x] = 0;
			b[y][x] = 0;
		}
}

void print_grid()
{
	for(int y = 0; y < rc; y++)
	{
		for(int x = 0; x < c; x++)
		{
			cout << t[y][x] << " ";
		}
		cout << endl;
	}
}

bool is_prime(int n)
{
	if(n == 0 || n == 1) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0) return false;
	return true;
}

int cpc_monsters(int x, int y)
{
	if(grid[y][x] == '#') return 0;
	
	int l_value = l[y][x];
	int r_value = r[y][x];
	int t_value = t[y][x];
	int b_value = b[y][x];
	
	int minval = 1000000;
	if(l_value < minval) minval = l_value;
	if(r_value < minval) minval = r_value;
	if(t_value < minval) minval = t_value;
	if(b_value < minval) minval = b_value;
	
	return primes_below[minval];
}

void solve()
{
	int ans = 0;
	cin >> rc >> c;
	for(int y = 0; y < rc; y++)
		for(int x = 0; x < c; x++)
			cin >> grid[y][x];
			
	// create the cummulative grids
	
	clear_arrs();
	
	// left
	for(int y = 0; y < rc; y++)
	{
		int sum = 0;
		for(int x = 0; x < c; x++)
		{
			l[y][x] = sum;
			if(grid[y][x] == '#') sum = 0;
			else sum++;
		}
	}
	
	// right
	for(int y = 0; y < rc; y++)
	{
		int sum = 0;
		for(int x = c - 1; x >= 0; x--)
		{
			r[y][x] = sum;
			if(grid[y][x] == '#') sum = 0;
			else sum++;
		}
	}
	
	// top
	for(int x = 0; x < c; x++)
	{
		int sum = 0;
		for(int y = 0; y < rc; y++)
		{
			t[y][x] = sum;
			if(grid[y][x] == '#') sum = 0;
			else sum++;
		}
	}
	
	// bottom
	for(int x = 0; x < c; x++)
	{
		int sum = 0;
		for(int y = rc - 1; y >= 0; y--)
		{
			b[y][x] = sum;
			if(grid[y][x] == '#') sum = 0;
			else sum++;
		}
	}
	
	for(int y = 0; y < rc; y++)
		for(int x = 0; x < c; x++)
			ans += cpc_monsters(x, y);
			
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	// clear primes_below
	for(int i = 0; i < 505; i++) primes_below[i] = 0;
		
	// find primes
	int cur = 0;
	for(int i = 0; i < 500; i++)
	{
		if(is_prime(i)) cur++;
		primes_below[i] = cur;
	}
	
	// for(int i = 0; i < 100; i++) cout << primes_below[i] << " ";
	// cout << endl;
	
	int t; cin >> t;
	while(t--) solve();
}