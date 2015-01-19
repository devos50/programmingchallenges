#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int d[n];
	int sum = 0;
	for(int i = 0; i < n; i++) { cin >> d[i]; sum += d[i]; }
	int s, t; cin >> s >> t; s--; t--;
	
	int cur = s;
	int curdist = 0;
	while(cur != t)
	{
		curdist += d[cur];
		cur = (cur + 1) % n;
	}
	cout << min(curdist, sum - curdist) << endl;
}