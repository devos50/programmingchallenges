//
//  main.cpp
//  bsheep
//
//  Created by M.A. de Vos on 23-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

typedef struct Point {
    int num;
    int x;
    int y;
	bool operator <(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
} Point;

map<int, map<int, bool> > cmap;

int cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (int)(B.y - O.y) - (A.y - O.y) * (int)(B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	
	// Sort points lexicographically
	sort(P.begin(), P.end());
	 
	// Build lower hull
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	 
	H.resize(k);
	return H;
}

Point bottom(Point p1, Point p2)
{
	if(p1.y < p2.y) return p1;
	else if(p1.y == p2.y && p1.x < p2.x) return p1;
	return p2;
}

bool containsPoint(Point p)
{
	if(cmap.find(p.x) != cmap.end() && cmap[p.x].find(p.y) != cmap[p.x].end()) return true;
	return false;
}

void solve()
{
	cmap.clear();
    int sheeps = 0;
    scanf("%d", &sheeps);
    
    vector<Point> orig_points;
    for(int i = 0; i < sheeps; i++)
    {
        Point p;
        scanf("%d %d", &p.x, &p.y);
        p.num = i + 1;
		if(!containsPoint(p))
		{
			orig_points.push_back(p);
			cmap[p.x][p.y] = true;
		} 
    }

	// convex hull
	vector<Point> hull = convex_hull(orig_points);
	
	// calculate the perimeter and the bottommost point
	double perimeter = 0.0;
	Point bottommost; bottommost.x = 1000000; bottommost.y = 1000000;
	for(vector<Point>::iterator it = hull.begin(); it != hull.end() - 1; it++)
	{
		Point p1 = *it;
		Point p2 = *(it+1);
		perimeter += sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
		bottommost = bottom(p1, bottommost);
	}
	printf("%.2f\n",perimeter);
	if(hull.size() == 1)
	{
		cout << hull[0].num << endl << endl;
		return;
	}
	hull.pop_back();
	
	// find the index of the lowest point
	int curIndex = 0;
	int bottomIndex = 0;
	bool hasFound = false;
	for(vector<Point>::iterator it = hull.begin(); it != hull.end(); it++)
	{
		if(it->num == bottommost.num) { bottomIndex = curIndex; hasFound = true; }
		if(hasFound) cout << it->num << " ";
		else curIndex++;
	}
	
	// print the first points
	for(vector<Point>::iterator it = hull.begin(); it != hull.end() - (hull.size() - curIndex); it++)
	{
		cout << it->num << " ";
	}
	
	cout << endl << endl;
}

int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    
    while(t--) solve();
    
    return 0;
}

