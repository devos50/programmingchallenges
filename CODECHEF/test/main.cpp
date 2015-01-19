#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int n; cin >> n;
		if(n != 42) cout << n << endl;
		else break;
	}
}