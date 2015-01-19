#include <iostream>

using namespace std;

void solve()
{
	double d; cin >> d;
	int u, n; cin >> u >> n;
	double lowest_cost = (double)u * d;
	int best_plan = 0;
	
	for(int i = 0; i < n; i++)
	{
		int m, c;
		double r;
		cin >> m >> r >> c;
			
		double cost = (double)c / (double)m + r * u;
		// cout << "cost of plan " << i + 1 << ": " << cost << endl;
		if(cost < lowest_cost)
		{
			best_plan = i + 1;
			lowest_cost = cost;
		}
	}
	cout << best_plan << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}