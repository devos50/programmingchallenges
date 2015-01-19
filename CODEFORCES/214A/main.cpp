#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, m; cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < 1005; i++)
		for(int j = 0; j < 1005; j++)
		{
			if(i * i + j == n && i + j * j == m) ans++;
		}
	cout << ans << endl;
}