#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int birds[n]; for(int i = 0; i < n; i++) cin >> birds[i];
	
	int shots; cin >> shots;
	for(int i = 0; i < shots; i++)
	{
		int x, wire; cin >> wire >> x;
		wire--; x--;
		int l = x;
		int r = birds[wire] - l - 1;
		// cout << "l: " << l << ", r: " << r << endl;
		
		birds[wire] = 0;
		if(wire != 0) birds[wire - 1] += l;
		if(wire != n - 1) birds[wire + 1] += r;
	}
	
	for(int i = 0; i < n; i++) cout << birds[i] << endl;
}