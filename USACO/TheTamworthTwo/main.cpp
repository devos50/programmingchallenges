/*
 ID: mdmarti1
 PROG: ttwo
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

char grid[10][10];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

set<long long> seen;

int main()
{
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");

	pair<int, int> cow_coords, farmer_coords;
	int cows_dir = 0, farmer_dir = 0; // 0 = north, 1 = east, 2 = south, 3 = west
    
	for(int y = 0; y < 10; y++)
	{
		for(int x = 0; x < 10; x++)
		{
			fin >> grid[y][x];
			if(grid[y][x] == 'F') farmer_coords = make_pair(x, y);
			else if(grid[y][x] == 'C') cow_coords = make_pair(x, y);
		}
	}
			
	// simulate
	int curminute = 1;
	while(true)
	{
		// move cows
		int newx = cow_coords.first + dx[cows_dir];
		int newy = cow_coords.second + dy[cows_dir];
		if(grid[newy][newx] == '*' || newx >= 10 || newx < 0 || newy >= 10 || newy < 0)
		{
			cows_dir++; cows_dir %= 4;
		}
		else cow_coords = make_pair(newx, newy);
		
		// move farmer
		newx = farmer_coords.first + dx[farmer_dir];
		newy = farmer_coords.second + dy[farmer_dir];
		
		if(grid[newy][newx] == '*' || newx >= 10 || newx < 0 || newy >= 10 || newy < 0)
		{
			farmer_dir++; farmer_dir %= 4;
		}
		else farmer_coords = make_pair(newx, newy);
		
		// seen this state?
		long long curstate = cow_coords.first + cow_coords.second * 100 + cows_dir * 10000 + farmer_coords.first * 1000000 + farmer_coords.second * 100000000 + farmer_dir * 1000000000000;
		if(seen.find(curstate) == seen.end()) seen.insert(curstate);
		else
		{
			fout << 0 << endl;
			break;
		}
		
		if(farmer_coords == cow_coords)
		{
			fout << curminute << endl;
			break;
		}
		
		curminute++;
	}

    return 0;
}