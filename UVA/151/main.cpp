#include <iostream>

using namespace std;

void solve(int n)
{
	n--;
	int turnoff, m;
	for(m = 1; m < n; m++)
	{
		turnoff = 0;
	    for(int i = 1;i <= n; i++)
	        turnoff = (turnoff + m) % i;
	    if( turnoff == 11) break;
	}
	cout << m << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int n; cin >> n;
		if(n == 0) break;
		solve(n);
	}
}