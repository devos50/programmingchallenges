#include <iostream>
#include <map>

#define LINT 100000000

using namespace std;

bool connected[55][55];
int dist[55][55];

void solve(int p, int r, int c)
{
	// clear connected
	for(int y = 0; y < p; y++)
		for(int x = 0; x < p; x++)
			connected[y][x] = false;
	
	map<string, int> nameMap;
	int counter = 0;
	for(int i = 0; i < r; i++)
	{
		string name1; cin >> name1;
		string name2; cin >> name2;
		// cout << "connection " << name1 << " to " << name2 << endl;
		if(nameMap.find(name1) == nameMap.end())
		{
			nameMap[name1] = counter;
			counter++;
		}
		if(nameMap.find(name2) == nameMap.end())
		{
			nameMap[name2] = counter;
			counter++;
		}
		
		int ind1 = nameMap[name1]; int ind2 = nameMap[name2];
		connected[ind1][ind2] = true; connected[ind2][ind1] = true;
	}
	
	// fw
	for(int y = 0; y < p; y++)
		for(int x = 0; x < p; x++)
			dist[y][x] = LINT;
	
	for(int i = 0; i < p; i++) dist[i][i] = 0;
	
	for(int y = 0; y < p; y++)
		for(int x = 0; x < p; x++)
			if(connected[y][x]) dist[y][x] = 1;
	
	for(int k = 0; k < p; k++)
		for(int i = 0; i < p; i++)
			for(int j = 0; j < p; j++)
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	/*				
	for(int y = 0; y < p; y++)
	{
		for(int x = 0; x < p; x++)
		{
			cout << dist[y][x] << " ";
		}
		cout << endl;
	}
	*/				
	// find answer
	int max = -1;
	for(int y = 0; y < p; y++)
		for(int x = 0; x < p; x++)
			if(dist[y][x] > max) max = dist[y][x];
	
	cout << "Network " << c << ": ";
	
	if(max == LINT) cout << "DISCONNECTED" << endl;
	else cout << max << endl;
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int p,r;
	int c = 1;
	while(true)
	{
		cin >> p >> r;
		if(p == 0 && r == 0) break;
		solve(p, r, c);
		c++;
	}
}