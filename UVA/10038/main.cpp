#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

void solve(int n)
{
	int vals[n];
	for(int i = 0; i < n; i++) cin >> vals[i];
	set<int> diffs;
	for(int i = 0; i < n - 1; i++)
	{
		int diff = abs(vals[i] - vals[i+1]);
		if(diff >= 1 && diff < n) diffs.insert(diff);
	}
	
	if(diffs.size() == n - 1) cout << "Jolly" << endl;
	else cout << "Not jolly" << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n) solve(n);
}