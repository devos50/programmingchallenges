#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long n, m; cin >> n >> m;
	long long curhouse = 0;
	long long total = 0;
	for(long long i = 0; i < m; i++)
	{
		long long house; cin >> house;
		house--;
		
		long long diff;
		if(curhouse == house) diff = 0;
		else if(curhouse > house) diff = n - (curhouse - house);
		else diff = house - curhouse;
		
		total += diff;
		// cout << "from " << curhouse << " to " << house << ": " << diff << endl;
		
		curhouse = house;
	}
	cout << total << endl;
}