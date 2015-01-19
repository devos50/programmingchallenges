#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct Point {
	int x;
	int y;
	bool operator <(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
} Point;

typedef struct Kingdom {
	bool hasPower;
	vector<Point> points;
} Kingdom;

vector<Kingdom> kingdoms;

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

bool containsPoint(Point p, vector<Point> points)
{
	for(vector<Point>::iterator it = points.begin(); it != points.end(); it++)
		if(it->x == p.x && it->y == p.y) return false;
	return true;
}

bool inKingdom(Point p, Kingdom k)
{
	k.points.push_back(p);
	vector<Point> hull = convex_hull(k.points);
	k.points.pop_back();
	return containsPoint(p, hull);
}

double kingdomArea(Kingdom k)
{
	k.points.push_back(k.points.front());
	double area = 0.0;
	for(int i = 0; i < k.points.size() - 1; i++)
	{
		Point p1 = k.points[i];
		Point p2 = k.points[i+1];
		area += (p1.x*p2.y - p2.x*p1.y);
	}
	
	return 0.5 * area;
}

int main(int argc, char *argv[]) 
{
	// lees kingdoms
	while(true)
	{
		int sites; cin >> sites;
		if(sites == -1) break;
		
		vector<Point> points;
		for(int i = 0; i < sites; i++)
		{
			Point p; cin >> p.x >> p.y;
			points.push_back(p);
		}
		
		// determine convex hull
		vector<Point> convex = convex_hull(points);
		Kingdom k; k.points = convex; k.hasPower = true;
		kingdoms.push_back(k);
	}
	
	// process missiles
	Point p;
	while(cin >> p.x && cin >> p.y)
	{
		for(vector<Kingdom>::iterator it = kingdoms.begin(); it != kingdoms.end(); it++)
			if(it->hasPower && inKingdom(p, *it)) it->hasPower = false;
	}
	
	double areasum = 0.0;
	for(vector<Kingdom>::iterator it = kingdoms.begin(); it != kingdoms.end(); it++)
	{
		if(!it->hasPower) areasum += kingdomArea(*it);
	}
	
	printf("%.2f\n", areasum);
}