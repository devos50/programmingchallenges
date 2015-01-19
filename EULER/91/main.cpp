#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define N 50

using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool hasRightAngle(double x1, double y1, double x2, double y2)
{
	double d1 = dist(0.0, 0.0, x1, y1); // OP
	double d2 = dist(x1, y1, x2, y2); // PQ
	double d3 = dist(0.0, 0.0, x2, y2); // OQ
	vector<double> vec; vec.push_back(d1); vec.push_back(d2); vec.push_back(d3);
	sort(vec.begin(), vec.end());
	
	if(d1 == 0.0 || d2 == 0.0 || d3 == 0.0) return false;
	
	// cout << "x1: " << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2: " << y2 << endl;
	// cout << "d1: " << d1 << ", d2: " << d2 << ", d3: " << d3 << endl;
	
	return abs(vec[0] * vec[0] + vec[1] * vec[1] - vec[2] * vec[2]) < 0.01;
}

int main(int argc, char *argv[]) 
{
	double ans = 0;
	for(double x1 = 0; x1 <= N; x1++)
		for(double y1 = 0; y1 <= N; y1++)
			for(double x2 = 0; x2 <= N; x2++)
				for(double y2 = 0; y2 <= N; y2++)
					if(hasRightAngle(x1, y1, x2, y2))
					{
						// cout << "(" << x1 << "," << y1 <<"), (" << x2 << "," << y2 << ")" << endl;
						ans++;
					}
	cout << ans / 2;
}