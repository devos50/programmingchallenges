#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int m, n; cin >> m >> n;
	
	int ans;
	if(m == 1) ans = n / 2;
	else
	{
		ans = (m / 2) * n;
		if(m % 2 != 0) ans += (n / 2);
	}
	
	cout << ans << endl;
}