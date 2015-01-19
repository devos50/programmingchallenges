#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			int n; cin >> n;
			if(n == 1)
			{
				cout << abs(2 - i) + abs(2 - j) << endl;
				return 0;
			}
		}
	}
}