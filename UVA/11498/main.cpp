#include <iostream>

using namespace std;

void solve(int n)
{
	int divx, divy; cin >> divx >> divy;
	for(int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		if(x == divx || y == divy) cout << "divisa" << endl;
		else if(x > divx && y > divy) cout << "NE" << endl;
		else if(x > divx && y < divy) cout << "SE" << endl;
		else if(x < divx && y > divy) cout << "NO" << endl;
		else cout << "SO" << endl;
	}
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