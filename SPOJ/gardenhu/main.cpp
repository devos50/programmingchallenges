#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct Point {
    int num;
    int x;
    int y;
	bool operator <(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
} Point;

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


int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	vector<Point> orig_points;
	for(int i = 0; i < n; i++)
	{
		Point p; cin >> p.x >> p.y;
		orig_points.push_back(p);
	}
	
	// convex hull
	vector<Point> hull = convex_hull(orig_points);
		
	// calculate the perimeter and the bottommost point
	double perimeter = 0.0;
	for(vector<Point>::iterator it = hull.begin(); it != hull.end() - 1; it++)
	{
		Point p1 = *it;
		Point p2 = *(it+1);
		perimeter += sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
	}
	printf("%d\n",(int)(perimeter));
}