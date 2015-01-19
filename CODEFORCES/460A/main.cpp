#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, m; cin >> n >> m;
	int curday = 0;
	while(n != 0)
	{
		n--;
		if(curday % m == 0) n++;
		curday++;
	}
	cout << curday - 1 << endl;
}