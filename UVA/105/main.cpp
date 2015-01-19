#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int maxX = 0;
	int heights[10005];
	int left, height, right;
	while(cin >> left && cin >> height && cin >> right)
	{
		for(int i = left; i < right; i++)
			heights[i] = max(heights[i], height);
		maxX = max(maxX, right);
	}
	
	int curHeight = 0;
	int curX = 1;
	string res = "";
	while(curX <= maxX)
	{
		if(heights[curX] != curHeight)
		{
			stringstream s;
			if(curX == 1) s << curX << " ";
			else s << curHeight << " " << curX << " ";
			curHeight = heights[curX];
			res += s.str();
		}
		curX++;
	}
	res += "0";
	cout << res << endl;
}