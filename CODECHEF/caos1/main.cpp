#include <iostream>

using namespace std;

char grid[55][55];
int rc, c;

bool is_cpc(int x, int y)
{
	if(grid[y][x] == '#') return false;
	
	// left
	int l = 0; int curx = x - 1;
	while(curx >= 0 && grid[y][curx] == '^') { l++; curx--; }
	
	// right
	int r = 0; curx = x + 1;
	while(curx < c && grid[y][curx] == '^') { r++; curx++; }
	
	// top
	int t = 0; int cury = y - 1;
	while(cury >= 0 && grid[cury][x] == '^') { t++; cury--; }
	
	// bottom
	int b = 0; cury = y + 1;
	while(cury < rc && grid[cury][x] == '^') { b++; cury++; }
	
	int minnum = 1000000;
	if(l < minnum) minnum = l;
	if(r < minnum) minnum = r;
	if(b < minnum) minnum = b;
	if(t < minnum) minnum = t;
	
	// cout << "x: " << x << ", y: " << y << ", l: " << l << ", r: " << r << ", b: " << b << ", t: " << t << endl;
	
	if(minnum >= 2) return true;
	return false;
}

void solve()
{
	int ans = 0;
	cin >> rc >> c;
	for(int y = 0; y < rc; y++)
		for(int x = 0; x < c; x++)
			cin >> grid[y][x];
			
	for(int y = 0; y < rc; y++)
		for(int x = 0; x < c; x++)
			if(is_cpc(x, y)) { ans++; }
			
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}