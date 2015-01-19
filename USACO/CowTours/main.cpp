/*
 ID: mdmarti1
 PROG: cowtour
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>

#define LINT 1E15
#define MAX(a,b) ((a) > (b) ? a : b)

// ans: 174.000000

using namespace std;

double shortest_dist[155][155];
bool conn[155][155];
int parent[155];
int size[155];
map<int, vector<int> > diammap;
double diamdists[155];

int find(int n)
{
	if(parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int x, int y)
{
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	size[ry] += size[rx];
	parent[rx] = parent[ry];
}

double dist(pair<double, double> p1, pair<double, double> p2)
{
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main()
{
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");

	int n; fin >> n;
	vector<pair<double, double> > coords;
	for(int i = 0; i < n; i++)
	{
		double x, y; fin >> x >> y;
		coords.push_back(make_pair(x, y));
	}
	
	// fw
	for(int y = 0; y < n; y++)
		for(int x = 0; x < n; x++)
			shortest_dist[y][x] = LINT;
					
	for(int i = 0; i < n; i++)
		shortest_dist[i][i] = 0;
		
	// fill in diam dists
	for(int i = 0; i < n; i++)
		diamdists[i] = 0;
	
	// fill the parent array
	for(int i = 0; i < 150; i++) parent[i] = i, size[i] = 1;
	
	// read the adjacency matrix and connect if needed
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < n; x++)
		{
			char c; fin >> c;
			if(c == '0') { conn[y][x] = false; continue; }
			else 
			{ 
				merge(x,y); 
				shortest_dist[y][x] = dist(coords[y], coords[x]);
				conn[y][x] = true;
			}
		}
	}
	
	// fw
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(shortest_dist[i][k] + shortest_dist[k][j] < shortest_dist[i][j])
					shortest_dist[i][j] = shortest_dist[i][k] + shortest_dist[k][j];
	
	// maak componenten
	for(int i = 0; i < n; i++)
		diammap[find(i)].push_back(i);
		
	// bereken van iedere component de diameter
	for(map<int, vector<int> >::iterator it = diammap.begin(); it != diammap.end(); it++)
	{
		double diam = 0;
		vector<int> nums = it->second;
		for(vector<int>::iterator it1 = nums.begin(); it1 != nums.end(); it1++)
		{
			for(vector<int>::iterator it2 = nums.begin(); it2 != nums.end(); it2++)
			{
				if(*it1 == *it2 || shortest_dist[*it1][*it2] == LINT) continue;
				if(shortest_dist[*it1][*it2] > diam) diam = shortest_dist[*it1][*it2];
			}
		}
		
		// vul de grootte in
		for(vector<int>::iterator it1 = nums.begin(); it1 != nums.end(); it1++)
		{
			diamdists[*it1] = diam;
		}
		
		cout << "diam of component: " << it->first << ", " << diam << endl;
	}
	
	// bereken afstanden
	double max_dists[n]; 
	for(int i = 0; i < n; i++)
	{
		double maxd = 0;
		for(int j = 0; j < n; j++)
		{
			if(i == j || shortest_dist[i][j] == LINT) continue;
			if(shortest_dist[i][j] > maxd) maxd = shortest_dist[i][j];
		}
		// cout << "max dist for " << (char)('A' + i) << ": " << maxd << endl;
		max_dists[i] = maxd;
	}
	
	double mindiam = LINT;
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < n; x++)
		{
			if(!conn[y][x] && find(x) != find(y))
			{
				double newdiam = MAX(diamdists[y], MAX(diamdists[x], max_dists[y] + dist(coords[y], coords[x]) + max_dists[x]));
				if(newdiam < mindiam) mindiam = newdiam;
				// cout << "connection between " << (char)('A' + y) << " and " << (char)('A' + x) << ", new diam: " << newdiam << endl;
			}
		}
	}
	fout << setprecision(6) << fixed << mindiam << endl;
	
    return 0;
}