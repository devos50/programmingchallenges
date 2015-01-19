#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <float.h>

using namespace std;

typedef struct Point {
	double x;
	double y;
} Point;

double distances[55][55];
int numislands;

void dijkstra(int start, int end)
{
	double best[numislands];
	double visited[numislands];
	for(int i = 0; i < numislands; i++)
	{
		best[i] = 100000;
		visited[i] = false;
	}
	
	best[start] = 0;
	
	for(int i = 0; i < numislands; i++)
	{
		double min = 100000;
		int currentnode = 0;
		for(int j = 0; j < numislands; j++)
		{
			if(!visited[j] && best[j] < min)
			{
				currentnode = j;
				min = best[j];
			}
		}
		
		visited[currentnode] = true;
		for(int j = 0; j < numislands; j++)
		{
			if(distances[currentnode][j] < 100000 && best[currentnode] + distances[currentnode][j] < best[j])
				best[j] = best[currentnode] + distances[currentnode][j];
		}
	}
	
	double shortest = best[end];
	printf("%.3f\n", shortest);
}

double determinePerpendicularDistance(Point p1, Point p2, Point p3)
{
	double labda = ((p3.x - p2.x) * (p1.x - p2.x) + (p3.y - p2.y) * (p1.y - p2.y)) / ((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
	if(labda < 0) labda = 0;
	else if(labda > 1) labda = 1;
		
	double d1 = p1.x - p2.x - labda * (p3.x - p2.x);
	double d2 = p1.y - p2.y - labda * (p3.y - p2.y);
	double distance = sqrt(d1*d1 + d2*d2);
	
	return distance;
}

double determineMinDistance(vector<Point> island1, vector<Point> island2)
{
	// itereer over ieder punt van island 1
	double minDistance = DBL_MAX;
	
	for(vector<Point>::iterator it = island1.begin(); it != island1.end(); it++)
	{
		int islandSize = island2.size();
		for(int i = 0; i < islandSize; i++)
		{
			double distance = determinePerpendicularDistance(*it, island2[i], island2[(i+1) % islandSize]);
			if(distance < minDistance) minDistance = distance;
		}
	}
	
	return minDistance;
}

void solve()
{
	int start, destination; cin >> numislands >> start >> destination;
	vector<vector<Point> > islands;
	for(int i = 0; i < numislands; i++)
	{
		vector<Point> points;
		int amountPoints; cin >> amountPoints;
		for(int j = 0; j < amountPoints; j++)
		{
			Point p; cin >> p.x >> p.y;
			points.push_back(p);
		}
		islands.push_back(points);
	}
	
	for(int y = 0; y < 55; y++)
		for(int x = 0; x < 55; x++)
			distances[y][x] = DBL_MAX;
	
	int counter1 = 0, counter2 = 0;
	for(vector<vector<Point> >::iterator it1 = islands.begin(); it1 != islands.end(); it1++)
	{
		counter2 = 0;
		vector<Point> island1 = *it1;
		
		for(vector<vector<Point> >::iterator it2 = islands.begin(); it2 != islands.end(); it2++)
		{
			vector<Point> island2 = *it2;
			double mindistance = determineMinDistance(island1, island2);
			
			if(mindistance < distances[counter1][counter2])
			{
				distances[counter1][counter2] = mindistance;
				distances[counter2][counter1] = mindistance;
			}
			counter2++;
		}
		counter1++;
	}
	dijkstra(start - 1, destination - 1);
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}