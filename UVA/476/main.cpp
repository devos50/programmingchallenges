#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Point {
	float x, y;
} Point;

typedef struct Rectangle {
	Point ul, lr;
} Rectangle;

bool contains_point(Rectangle r, float x, float y)
{
	return (x < r.lr.x && x > r.ul.x && y < r.ul.y && y > r.lr.y);
}

vector<Rectangle> rectangles;

int main(int argc, char *argv[]) 
{
	// read rectangles
	string s;
	while(true)
	{
		cin >> s;
		if(s == "*") break;
		
		Point ul; cin >> ul.x >> ul.y;
		Point lr; cin >> lr.x >> lr.y;
		Rectangle r; r.ul = ul; r.lr = lr;
		rectangles.push_back(r);
	}
	
	// read and process points
	float x, y;
	int count = 1;
	while(true)
	{
		cin >> x >> y;
		if(abs(9999.9 - x) < 10E-4 && abs(9999.9 - y) < 10E-4) break;
		
		bool contained = false;
		for(int i = 0; i < rectangles.size(); i++)
		{
			Rectangle r = rectangles[i];
			
			if(contains_point(r, x, y))
			{
				contained = true;
				cout << "Point " << count << " is contained in figure " << i + 1 << endl;
			}
		}
		
		if(!contained)
		{
			cout << "Point " << count << " is not contained in any figure" << endl;
		}
		
		count++;
	}
}