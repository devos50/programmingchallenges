#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] == s[i+1]) ans++;
	}
	cout << ans << endl;
}