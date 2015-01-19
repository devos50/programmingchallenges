#include <iostream>
#include <math.h>

using namespace std;

void solve(long n)
{
	double s = sqrt(n);
	if(s == (int)s) cout << "yes" << endl;
	else cout << "no" << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		long n; cin >> n;
		if(n == 0) break;
		solve(n);
	}
}