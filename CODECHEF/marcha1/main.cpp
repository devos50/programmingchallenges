#include <iostream>

using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	int notes[n];
	for(int i = 0; i < n; i++)
	{
		cin >> notes[i];
	}
	
	// generate subsets
	for(int i = 0; i < (1 << n); i++)
	{
		int subset = 0;
		for(int j = 0; j < n; j++)
		{
			if(i & (1 << j)) subset += notes[j];
		}
		
		if(subset == m) { cout << "Yes" << endl; return; }
	}
	cout << "No" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}