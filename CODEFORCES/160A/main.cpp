#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	vector<int> coins; 
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int v; cin >> v;
		sum += v;
		coins.push_back(v);
		
	}
	sort(coins.begin(), coins.end());
	
	int yourval = 0, twinval = sum;
	int coinstaken = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		yourval += coins[i];
		twinval -= coins[i];
		coinstaken++;
		if(yourval > twinval) break;
	}
	cout << coinstaken << endl;
}