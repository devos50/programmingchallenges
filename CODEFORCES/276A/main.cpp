#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k; cin >> n >> k;
	int maxjoy = -2000000000;
	for(int i = 0; i < n; i++)
	{
		int f, t; cin >> f >> t;
		int joy = f;
		if(t > k) joy = f - (t - k);
		if(joy > maxjoy) maxjoy = joy;
	}
	cout << maxjoy << endl;
}