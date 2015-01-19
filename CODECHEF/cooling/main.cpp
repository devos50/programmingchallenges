#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> weights_pie;
	vector<int> weights_cooling;
	
	for(int i = 0; i < n; i++)
	{
		int w; cin >> w;
		weights_pie.push_back(w);
	}
	for(int i = 0; i < n; i++)
	{
		int w; cin >> w;
		weights_cooling.push_back(w);
	}
	
	sort(weights_pie.begin(), weights_pie.end());
	sort(weights_cooling.begin(), weights_cooling.end());
	
	int ans = 0;
	int p_ind = 0; int c_ind = 0;
	while(p_ind < n && c_ind < n)
	{
		if(weights_pie[p_ind] <= weights_cooling[c_ind])
		{
			ans++;
			p_ind++;
			c_ind++;
		}
		else
		{
			c_ind++;
		}
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}