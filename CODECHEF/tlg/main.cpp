#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int r; cin >> r;
	int maxdiff = -1;
	bool p1wins = true;
	int p1score = 0, p2score = 0;
	for(int i = 0; i < r; i++)
	{
		int p1s, p2s; cin >> p1s >> p2s;
		p1score += p1s; p2score += p2s;
		
		int diff = p1score - p2score;
		if(diff < 0) diff *= -1;
		if(diff > maxdiff)
		{
			maxdiff = diff;
			if(p1score > p2score) p1wins = true;
			else p1wins = false;
		}
	}
	
	if(p1wins) cout << "1 ";
	else cout << "2 ";
	cout << maxdiff << endl;
	
}