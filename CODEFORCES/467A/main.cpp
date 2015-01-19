#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int ans = 0;
	while(n--)
	{
		int pi, qi; cin >> pi >> qi;
		if(qi - pi >= 2) ans++;
	}
	cout << ans << endl;
}