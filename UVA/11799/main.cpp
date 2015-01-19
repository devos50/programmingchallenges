#include <iostream>

using namespace std;

void solve(int t)
{
	int n; cin >> n;
	int max = -1000000;
	for(int i = 0; i < n; i++)
	{
		int num; cin >> num;
		if(num > max) max = num;
	}
	cout << "Case " << t << ": " << max << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}