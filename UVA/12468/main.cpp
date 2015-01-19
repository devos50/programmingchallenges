#include <iostream>
#include <cmath>

using namespace std;

void solve(int a, int b)
{
	if(a > b)
	{
		int diffdown = a - b;
		int diffup = 99 - a + b + 1;
		cout << min(diffdown, diffup) << endl;
	}
	else
	{
		int diffdown = b - a;
		int diffup = 99 - b + a + 1;
		cout << min(diffdown, diffup) << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int a, b;
	while(true)
	{
		cin >> a >> b;
		if(a == -1 && b == -1) break;
		solve(a, b);
	}
}