#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int a, int d)
{
	vector<int> attack, defend;
	for(int i = 0; i < a; i++) { int n; cin >> n; attack.push_back(n); }
	for(int i = 0; i < d; i++) { int n; cin >> n; defend.push_back(n); }
	
	sort(defend.begin(), defend.end());
	int dist = defend[1];
	
	for(int i = 0; i < a; i++)
	{
		if(attack[i] < dist) { cout << "Y" << endl; return; }
	}
	cout << "N" << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int a, d; cin >> a >> d;
		if(a == 0 && d == 0) break;
		solve(a, d);
	}
}