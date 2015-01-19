#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int coins[n];
	for(int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < coins[i]; j++)
		{
			if(i != n - 1) cout << "RLP";
			else cout << "LRP";
		}
		if(i != n - 1) cout << "R";
	}
}