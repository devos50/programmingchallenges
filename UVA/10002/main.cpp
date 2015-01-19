#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Point {
	int x;
	int y;
};

void solve(int m)
{
	vector<Point> points;
	for(int i = 0; i < m; i++)
	{
		Point p;
		cin >> p.x >> p.y;
		points.push_back(p);
	}
	
	// calculate area
	double area = 0;
	for(int i = 0; i < m-1; i++)
		area += (points[i].x*points[i+1].y - points[i+1].x*points[i].y);
	area /= 2.0;
	
	cout << "area: " << area << endl;
	
	// calculate the center
	double cx, cy;
	for(int i = 0; i < m-1; i++)
	{
		cx += ((points[i].x+points[i+1].x)*(points[i].x*points[i+1].y-points[i+1].x*points[i].y));
		cy += ((points[i].y+points[i+1].y)*(points[i].x*points[i+1].y-points[i+1].x*points[i].y));
	}
	
	cx /= (6.0*area);
	cy /= (6.0*area);
	
	printf("%.3f %.3f\n", cx, cy);
}

int main(int argc, char *argv[]) 
{
	int m;
	while(true)
	{
		cin >> m;
		if(m < 3) break;
		solve(m);
	}
}