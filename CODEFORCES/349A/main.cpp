#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int b25 = 0, b50 = 0, b100 = 0;
	for(int i = 0; i < n; i++)
	{
		int bil; cin >> bil;
		if(bil == 25)
		{
			b25++;
		}
		else if(bil == 50)
		{
			b50++;
			if(b25 == 0)
			{
				cout << "NO" << endl;
				return 0;
			}
			b25--;
		}
		else if(bil == 100)
		{
			b100++;
			if(b25 > 0 && b50 > 0) // give 1x 25, 1x 50
			{
				b25--;
				b50--;
			}
			else if(b25 >= 3) // give 3x 35
			{
				b25 -= 3;
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}