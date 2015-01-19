#include <iostream>
#include <set>
#include <queue>
#include <fstream>

#define LINT 1000000000
#define kGridSize 80

using namespace std;

int grid[kGridSize][kGridSize];
int dx[3] = {0, 1, 0};
int dy[3] = {-1, 0, 1};
int d[10000];

struct compare  
 {  
   bool operator()(const int& l, const int& r)  
   {  
       return d[l] > d[r];  
   }  
 };

// retourneert de lengte van het kortste pad tussen twee nodes
int shortest_path(int start)
{
	int cpy = start;
	int startY = cpy % 100; cpy /= 100;
	int startX = cpy;
	
	for(int i = 0; i < 10000; i++) d[i] = LINT;
	
	set<int> settled;
	priority_queue<int, vector<int>, compare> unsettled;
	unsettled.push(start);
	d[start] = grid[startY][startX];
	
	while(!unsettled.empty())
	{
		int u = unsettled.top(); unsettled.pop();
		int cpy = u;
		int curY = cpy % 100; cpy /= 100;
		int curX = cpy;
		settled.insert(u);
		
		// relaxatie van de buren
		for(int i = 0; i < 3; i++)
		{
			int newX = curX + dx[i];
			int newY = curY + dy[i];
			int newCode = newX * 100 + newY;
			if(newX >= kGridSize || newX < 0 || newY >= kGridSize || newY < 0) continue;
			
			if(settled.find(newCode) != settled.end()) continue;
			
			if(d[newCode] > d[u] + grid[newY][newX])
			{
				d[newCode] = d[u] + grid[newY][newX];
				unsettled.push(newCode);
			}
		}
	}
	
	int min = LINT;
	for(int i = 0; i < kGridSize; i++)
	{
		int dist = d[(kGridSize - 1) * 100 + i];
		if(dist < min) min = dist;
	}
	
	return min;
}

int main(int argc, char *argv[]) 
{
	fstream file("matrix.txt");
	for(int i = 0; i < kGridSize; i++)
		for(int j = 0; j < kGridSize; j++)
		{
			file >> grid[i][j];
		}
		
	int min = LINT;
	for(int i = 0; i < kGridSize; i++)
	{
		int dist = shortest_path(i);
		if(dist < min) min = dist;
	}
	cout << min;
}