#include <iostream>

using namespace std;

void solve(int n)
{
	if(n == 0)
	{
		cout << 1 << endl;
		return;
	}
	long res = 2;
	for(int i = 2; i <= n; i++) res += i;
	cout << res << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int n; cin >> n;
		if(n < 0) break;
		solve(n);
	}
}