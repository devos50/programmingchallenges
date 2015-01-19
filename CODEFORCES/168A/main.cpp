#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, x, y; cin >> n >> x >> y;
	int needed = ceil((double)n * ((double)y/100.0));
	
	if(x >= needed) cout << "0" << endl;
	else cout << needed - x << endl;
	
}