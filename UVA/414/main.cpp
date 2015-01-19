#include <iostream>

using namespace std;

void solve(int n)
{
	int spaces[n];
	int minSpaces = 10000;
	string s;
	getline(cin, s);
	for(int i = 0; i < n; i++)
	{
		getline(cin, s);
		int amountSpaces = 0;
		for(int j = 0; j < 25; j++)
			if(s.at(j) == ' ') amountSpaces++;
		spaces[i] = amountSpaces;
		if(spaces[i] < minSpaces) minSpaces = spaces[i];
	}
	
	int maxchars = 25 - minSpaces;
	// cout << "maxchars: " << maxchars << endl;
	int emptyplaces = 0;
	for(int i = 0; i < n; i++)
	{
		int charshere = 25 - spaces[i];
		emptyplaces += (maxchars - charshere);
	}
	cout << emptyplaces << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int n; cin >> n;
		if(n == 0) break;
		solve(n);
	}
}