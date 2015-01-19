	#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

map<pair<int, int>, int> nums;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

// ifstream fin("E.in");
// ofstream fout("E.out");

void solve()
{
	string s; cin >> s;
	
	nums.clear();
	
	nums[make_pair(0,0)] = 1;
	for(int i = 0; i < 4; i++)
	{
		int newx = dx[i];
		int newy = dy[i];
		nums[make_pair(newx, newy)] = i + 2;
	}
	
	stringstream ss; ss << s;
	string buf;
	
	int curx = 0, cury = 0;
	while(getline(ss, buf, ','))
	{
		int t = -1;
		if(buf == "U") t = 0;
		else if(buf == "D") t = 1;
		else if(buf == "L") t = 2;
		else if(buf == "R") t = 3;
		else break;
		curx += dx[t], cury += dy[t];
		
		// fill
		for(int i = 0; i < 4; i++)
		{
			int newx = curx + dx[i];
			int newy = cury + dy[i];
			if(nums.find(make_pair(newx, newy)) == nums.end()) // not in
				nums[make_pair(newx, newy)] = i + 2;
		}
	}
	
	int sum = 0;
	for(map<pair<int, int>, int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		sum += it->second;
	}
	cout << sum << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}