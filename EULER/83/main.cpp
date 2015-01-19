#include <iostream>
#include <set>
#include <queue>
#include <fstream>

#define LINT 1000000000
#define kGridSize 80

using namespace std;

int grid[kGridSize][kGridSize];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int d[10000];

struct compare  
 {  
   bool operator()(const int& l, const int& r)  
   {  
       return d[l] > d[r];  
   }  
 };

// retourneert de lengte van het kortste pad tussen twee nodes
int shortest_path(int start, int end)
{
	int startY = start % 100; start /= 100;
	int startX = start;
	int endY = end % 100;
	int endX = end / 100;
	
	for(int i = 0; i < 10000; i++) d[i] = LINT;
	
	set<int> settled;
	priority_queue<int, vector<int>, compare> unsettled;
	unsettled.push(0);
	d[0] = grid[0][0];
	
	while(!unsettled.empty())
	{
		int u = unsettled.top(); unsettled.pop();
		int cpy = u;
		int curY = cpy % 100; cpy /= 100;
		int curX = cpy;
		// cout << "curx: " << curX << ", cur y: " << curY << endl;
		settled.insert(u);
		
		// relaxatie van de buren
		for(int i = 0; i < 4; i++)
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
	return d[end];
}

int main(int argc, char *argv[]) 
{
	fstream file("matrix.txt");
	for(int i = 0; i < kGridSize; i++)
		for(int j = 0; j < kGridSize; j++)
		{
			file >> grid[i][j];
		}
	
	cout << shortest_path(0, (kGridSize - 1) * 100 + (kGridSize - 1));
}