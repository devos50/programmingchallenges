#include <iostream>

using namespace std;

void solve(int n)
{
	long long pilesize[n];
	for(int i = 0; i < n; i++) cin >> pilesize[i];
	
	long long sum = pilesize[0];
	for(int i = 1; i < n; i++) sum = sum ^ pilesize[i];
	
	// cout << "sum: " << sum << endl;
	
	if(sum != 0) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}
}