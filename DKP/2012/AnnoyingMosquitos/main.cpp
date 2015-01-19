#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

typedef struct Mosquito
{
	int x;
	int y;
	bool isHit;
} Mosquito;

void solve()
{
	int numMosquitos; cin >> numMosquitos;
	list<Mosquito> mosquitos;
	
	for(int i = 0; i < numMosquitos; i++)
	{
		Mosquito m;
		m.isHit = false;
		cin >> m.x; cin >> m.y;
		m.x += 1000; m.y += 1000;
		mosquitos.push_back(m);
	}
	
	// geef klap
	int attempts; cin >> attempts;
	int hits = 0;
	for(int i = 0; i < attempts; i++)
	{
		int midpointX, midpointY; cin >> midpointX >> midpointY;
		midpointX += 1000; midpointY += 1000;
		for(list<Mosquito>::iterator it = mosquitos.begin(); it != mosquitos.end(); it++)
		{
			if(it->isHit == true) continue;
			
			if(abs(it->x - midpointX) <= 50 && abs(it->y - midpointY) <= 50)
			{
				it->isHit = true;
				hits++;
			}
		}
	}
	cout << hits << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}