#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long x = 1, y = 1;
	for(int i = 0; i < 100; i++)
	{
		if(y > 10E12) break;
		long long old_x = x, old_y = y;
		x = 3 * old_x + 2 * old_y - 2;
		y = 4 * old_x + 3 * old_y - 3;
		cout << "(" << x << ", " << y << ")" << endl;
	}
}