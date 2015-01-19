#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	int m = 100000;
	int needed[5] = { 1, 1, 2, 7, 4 };
	for(int i = 0; i < 5; i++)
	{
		int n; cin >> n;
		m = min(m, n / needed[i]);
	}
	cout << m << endl;
}