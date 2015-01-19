#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		unsigned long long k; cin >> k;
		cout << 192 + 250 * (k - 1) << endl;
	}
}