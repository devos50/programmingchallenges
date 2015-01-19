#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int w; cin >> w;
	for(int i = 1; i < w; i++)
	{
		int b = w - i;
		if(i % 2 == 0 && b % 2 == 0) { cout << "YES" << endl; return 0; };
	}
	cout << "NO" << endl;
}