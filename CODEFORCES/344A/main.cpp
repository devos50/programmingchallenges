#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	string cur; cin >> cur;
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
		string c; cin >> c;
		if(cur[1] == c[0]) ans++;
		cur = c;
	}
	cout << ans + 1 << endl;
}