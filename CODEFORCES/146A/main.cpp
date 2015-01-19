#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int digs[n];
	for(int i = 0; i < n; i++)
	{
		char c; cin >> c;
		digs[i] = c - '0';
	}
	
	// check 4/7
	for(int i = 0; i < n; i++)
	{
		if(digs[i] != 4 && digs[i] != 7)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	
	// check sums
	int sumfirst = 0, sumlast = 0;
	for(int i = 0; i < n / 2; i++)
		sumfirst += digs[i];
	for(int i = n / 2; i < n; i++)
		sumlast += digs[i];
		
	if(sumfirst == sumlast) cout << "YES" << endl;
	else cout << "NO" << endl;
}