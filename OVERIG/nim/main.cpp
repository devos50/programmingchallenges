#include <iostream>
#include <sstream>

using namespace std;

void solve(int pieces[], int n)
{
	int nimsums[n];
	int nimsum = pieces[0];
	for(int i = 1; i < n; i++) nimsum = nimsum ^ pieces[i];
	
	cout << "nim sum: " << nimsum << endl;
	for(int i = 0; i < n; i++) nimsums[i] = pieces[i] ^ nimsum;
	
	// find the largest pile
	int max = -1;
	for(int i = 0; i < n; i++)
		if(pieces[i] > max)
			max = pieces[i];
	
	// largest pile decreasing?
	for(int i = 0; i < n; i++)
	{
		if(pieces[i] == max && nimsums[i] < pieces[i])
		{
			cout << "CAKE " << i << " PIECES " << pieces[i] - nimsums[i] << endl;
			return;
		}
	}
	
	// no winning move possible
	string lowest = "Z";
	for(int i = 0; i < n; i++)
	{
		if(pieces[i] == max) 
		{
			stringstream s; s << "CAKE " << i << " PIECES " << 1 << endl;
			if(s.str() < lowest) lowest = s.str();
		}
	}
	cout << lowest;
}

int main(int argc, char *argv[]) 
{
	if(string("1") < string("110")) cout << "test" << endl;
	int n = 3; int pieces[3] = {3,3,112};
	solve(pieces, n);
}