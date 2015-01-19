#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

using namespace std;

void solve()
{
	double r; cin >> r;
	cout << 2 * r << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}