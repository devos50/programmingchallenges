#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int min_val = 10000, max_val = -1;
	int vals[n]; 
	for(int i = 0; i < n; i++) 
	{
		int v; cin >> v;
		if(v < min_val) min_val = v;
		if(v > max_val) max_val = v;
		vals[i] = v;
	}
	
	// find max val ind
	int maxind = 0;
	for(int i = 0; i < n; i++)
		if(vals[i] == max_val)
		{
			maxind = i;
			break;
		}
		
	// find min val ind
	int minind = 0;
	for(int i = n - 1; i >= 0; i--)
		if(vals[i] == min_val)
		{
			minind = i;
			break;
		}
	
	// calculate swaps needed
	int swaps = maxind + (n - minind - 1);
	if(maxind > minind) swaps--;
	cout << swaps << endl;
}