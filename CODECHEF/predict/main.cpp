#include <iostream>
#include <cstdio>

using namespace std;

void solve()
{
	long double pa; cin >> pa;
	
	if(pa < 0.5) pa = 1.0 - pa;
	
	// double coeff = (pa * (2.0 * (1.0 - pa))) - (1.0 - pa);
	long double coeff = 2.0 * pa - 2 * pa * pa - (1.0 - pa);
	printf("%.7Lf\n", 10000.0 + 10000.0 * coeff);
	// cout << 10000.0 + 10000.0 * coeff << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}