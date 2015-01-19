#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k; cin >> n >> k;
	vector<int> sq;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		sq.push_back(a);
	}
	sort(sq.begin(), sq.end());
	
	if(sq.size() < k) cout << "-1" << endl;
	else cout << sq[sq.size() - k] << " " << sq[sq.size() - k] << endl;
}