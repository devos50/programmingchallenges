#include <iostream>

using namespace std;

void solve()
{
	int days, parties; cin >> days >> parties;
	int hartalRate[parties];
	for(int i = 0; i < parties; i++) cin >> hartalRate[i];
	
	bool hartals[days]; for(int i = 0; i < days; i++) hartals[i] = false;
	int numhartals = 0;
	for(int i = 0; i < parties; i++)
	{
		for(int j = hartalRate[i] - 1; j < days; j += hartalRate[i])
		{
			if(j >= 5 && ((j - 5) % 7 == 0)) continue; // friday
			if(j >= 6 && ((j - 6) % 7 == 0)) continue; // saturday
			if(hartals[j]) continue;
			else { numhartals++; hartals[j] = true; }
		}
	}
	cout << numhartals << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}