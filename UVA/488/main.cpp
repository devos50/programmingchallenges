#include <iostream>

using namespace std;

void solve(bool lastCase)
{
	int amp, freq; cin >> amp >> freq;
	for(int i = 0; i < freq; i++)
	{
		// build the first part of the wave
		for(int i = 1; i <= amp; i++)
		{
			for(int j = 1; j <= i; j++) cout << i;
			cout << endl;
		}
		// build the lower part
		for(int i = amp - 1; i >= 1; i--)
		{
			for(int j = i; j >= 1; j--) cout << i;
			cout << endl;
		}
		if(i != freq - 1) cout << endl;
	}
	
	if(!lastCase) cout << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = t; i > 0; i--) solve((i == 1));
}