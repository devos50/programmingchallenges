#include <iostream>
#include <vector>

using namespace std;

typedef struct Robot {
	int x;
	int y;
	int dir; // n = 0, e = 1, s = 2, w = 3
} Robot, Fallpos;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int xsize, ysize;
vector<Fallpos> fallpositions;

bool fallposExists(Robot r)
{
	for(vector<Fallpos>::iterator it = fallpositions.begin(); it != fallpositions.end(); it++)
	{
		if(it->x == r.x && it->y == r.y) return true;
	}
	return false;
}

void solve(int robotx)
{
	int roboty; cin >> roboty;
	char dir; cin >> dir;
	
	Robot r; r.x = robotx; r.y = roboty;
	if(dir == 'N') r.dir = 0;
	else if(dir == 'E') r.dir = 1;
	else if(dir == 'S') r.dir = 2;
	else if(dir == 'W') r.dir = 3;
	
	string commands; cin >> commands;
	bool isLost = false;
	for(int i = 0; i < commands.size(); i++)
	{
		if(commands.at(i) == 'R') r.dir = (r.dir + 1) % 4;
		else if(commands.at(i) == 'L')
		{
			if(r.dir == 0) r.dir = 3;
			else r.dir--;
		}
		else if(commands.at(i) == 'F')
		{
			if((r.x == 0 && r.dir == 3) || (r.x == xsize && r.dir == 1) || (r.y == 0 && r.dir == 2) || (r.y == ysize && r.dir == 0))
			{
				// robot is about to fall
				if(fallposExists(r)) { continue; }
				else
				{
					Fallpos fp;
					fp.x = r.x; fp.y = r.y;
					fallpositions.push_back(fp);
					isLost = true;
					break;
				}
			}
			else
			{
				r.x += dx[r.dir];
				r.y += dy[r.dir];
			}
		}
		// cout << "command: " << commands.at(i) << endl;
		// cout << r.x << " " << r.y << " " << r.dir << endl;
		
	}
	
	if(r.dir == 0) dir = 'N';
	else if(r.dir == 1) dir = 'E';
	else if(r.dir == 2) dir = 'S';
	else if(r.dir == 3) dir = 'W';
	cout << r.x << " " << r.y << " " << dir << ((isLost) ? " LOST" : "");
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	cin >> xsize >> ysize;
	
	int robotx;
	while(cin >> robotx) solve(robotx);
}