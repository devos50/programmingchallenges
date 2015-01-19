#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve()
{
	priority_queue<int, vector<int>, greater<int> > gz, mgz;
	
	int num_gz, num_mgz; cin >> num_gz >> num_mgz;
	for(int i = 0; i < num_gz; i++) { int n; cin >> n; gz.push(n); }
	for(int i = 0; i < num_mgz; i++) { int n; cin >> n; mgz.push(n); }
	
	while(true)
	{
		// vector<int>::iterator min_gz = min_element(gz.begin(), gz.end());
		// vector<int>::iterator min_mgz = min_element(mgz.begin(), mgz.end());
		int min_gz = gz.top();
		int min_mgz = mgz.top();
		// cout << "min gz: " << *min_gz << ", min mgz: " << *min_mgz << endl;
		if(min_gz < min_mgz) gz.pop();
		else mgz.pop();
		
		// cout << "gz size: " << gz.size() << ", mgz: " << mgz.size() << endl;
		
		if(gz.size() == 0) { cout << "MechaGodzilla" << endl; break; }
		else if(mgz.size() == 0) { cout << "Godzilla" << endl; break; }
	}
}

int main(int argc, char *argv[])
{
	int t; cin >> t;
	while(t--) solve();
}