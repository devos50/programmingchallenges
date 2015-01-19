#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--)
	{
		int a; cin >> a;
		int b = 180 - a;
		if(360 % b == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}