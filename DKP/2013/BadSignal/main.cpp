#include <iostream>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solve()
{
	double n, b; cin >> n >> b;
	double x, y; cin >> x >> y;
	
	double ri_a[1000005];
	double ri_sum = 0.0;
	
	for(int i = 0; i < n; i++)
	{
		double xi, yi, si; cin >> xi >> yi >> si;
		
		double d = dist(x, y, xi, yi);
		double ri = si / (d * d);
		ri_a[i] = ri;
		ri_sum += ri;
	}
	
	// can the signal be made out?
	for(int i = 0; i < n; i++)
	{
		if(ri_a[i] > 6 * (b + (ri_sum - ri_a[i])))
		{
			cout << i + 1 << endl;
			return;
		}
	}
	
	cout << "NOISE" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}