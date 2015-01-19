#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int x[n], y[n], z[n];
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> z[i];
		
	int xsum = 0, ysum = 0, zsum = 0;
	for(int i = 0; i < n; i++)
	{
		xsum += x[i];
		ysum += y[i];
		zsum += z[i];
	}
	
	if(xsum == 0 && ysum == 0 && zsum == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}