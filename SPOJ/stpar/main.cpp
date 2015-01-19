#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(int n)
{
	vector<int> trucks;
	for(int i = 0; i < n; i++) { int t; cin >> t; trucks.push_back(t); }
	
	stack<int> lane; int need = 1;
	bool state = true;
	for (int i = 0; i < trucks.size(); i++) {
		while (!lane.empty() && lane.top() == need) {
			need++;
			lane.pop();
		}
		if (trucks[i] == need) {
			need++;
		} else if (!lane.empty() && lane.top() < trucks[i]) {
			state = false;
			break;
		} else {
			lane.push(trucks[i]);
		}
	}
	if (state) cout << "yes" << "\n";
	else cout << "no" << "\n";
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int n; cin >> n;
		if(n == 0) break;
		solve(n);
	}
}