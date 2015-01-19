#include <iostream>

using namespace std;

int rectangles(int w, int h)
{
	int ans = 0;
	for(int i = 1; i <= w; i++)
	{
		for(int j = 1; j <= h; j++)
		{
			int wmoves = 1 + (w - i);
			int hmoves = 1 + (h - j);
			ans += wmoves * hmoves;
			// cout << "w: " << i << ", h: " << j << ": " << wmoves * hmoves << endl;
		}
	}
	return ans;
}

int main(int argc, char *argv[]) 
{
	int closest = 0;
	int area = 0;
	for(int i = 1; i < 90; i++)
		for(int j = 0; j < 90; j++)
		{
			int pos = rectangles(i, j);
			if(abs(2000000 - pos) < abs(2000000 - closest))
			{
				closest = pos;
				area = i * j;
			}
		}
	cout << "closest: " << closest << endl;
	cout << area << endl;
}