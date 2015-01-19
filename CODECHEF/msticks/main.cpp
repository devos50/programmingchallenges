#include <iostream>

#define LINT 1000000000

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	double burntimes[n];
	for(int i = 0; i < n; i++) cin >> burntimes[i];
	int q; cin >> q;
	while(q--)
	{
		int l, r; cin >> l >> r;
		
		// find min between l and r
		double min = LINT;
		for(int i = l; i <= r; i++)
			if(burntimes[i] < min) min = burntimes[i];
		
		// find the time till everything is burned
		double max = -1.0;
		for(int i = 0; i < n; i++)
		{
			if(i >= l && i <= r)
			{
				double ans = (burntimes[i] - min) / 2.0;
				if(ans > max) max = ans;
			}
			else
			{
				if(burntimes[i] > max) max = burntimes[i];
			}
		}
		printf("%.1f\n", min + max);
	}
}