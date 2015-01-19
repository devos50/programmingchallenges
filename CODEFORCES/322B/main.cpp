#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int r, g, b; cin >> r >> g >> b;
	int ans = 0;
	
	int n = min(r, min(g, b));
	ans += n;
	r -= n; g -= n; b -= n;
	
	ans += r / 3;
	ans += g / 3;
	ans += b / 3;
	cout << ans << endl;
}