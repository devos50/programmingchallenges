#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> vec;
	for(int i = 0; i < n; i++)
	{
		int num; cin >> num;
		vec.push_back(num);
	}
	
	int k; cin >> k;
	int num = vec[k - 1];
	
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < n; i++)
	{
		if(vec[i] == num) { cout << i + 1 << endl; break; }
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}