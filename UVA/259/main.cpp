#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int s, t;
int m, n;
map<int, vector<int> > adj;
int capacity[100][100];

// source = 80, drain = 81

int find_path() 
{
	// bfs
	queue<int> q;
	q.push(s);
	bool visited[n+5]; for(int i = 0; i < n+5; i++) visited[i] = false;
	visited[s] = true;
	int from[n+5]; for(int i = 0; i < n+5; i++) from[i] = -1;
	while(q.size() != 0)
	{
		int cur = q.front(); q.pop();
		vector<int> vec = adj[cur];
		for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			if(!visited[*it] && capacity[cur][*it] > 0)
			{
				q.push(*it); visited[*it] = true; from[*it] = cur;
				if(*it == t) break;
			}
		}
	}
	
	// compute bottleneck
	int cur = t, path_cap = INT_MAX;
	while(from[cur] > -1)
	{
		int prev = from[cur];
		path_cap = min(path_cap, capacity[prev][cur]);
		cur = prev;
	}
	
	// augmentation
	cur = t;
	while(from[cur] > -1)
	{
		int prev = from[cur];
		capacity[prev][cur] -= path_cap;
		capacity[cur][prev] += path_cap;
		cur = prev;
	}
	
	if(path_cap == INT_MAX) return 0;
	else return path_cap;
}

int max_flow()
{
	int result = 0;
	while(true)
	{
		int path_capacity = find_path();
		if(path_capacity == 0) break;
		else result += path_capacity;
	}
	return result;
}

void solve(vector<string> program)
{
	adj.clear();
	s = 80, t = 81, n = 100;
	for(int i = 0; i < 10; i++)
	{
		adj[80].push_back(i); capacity[80][i] = 1; capacity[i][80] = 0;
	}
	
	int totaljobs = 0;
	for(vector<string>::iterator it = program.begin(); it != program.end(); it++)
	{
		string s = *it;
		char pr = s[0]; int prnum = pr - 'A' + 10;
		int amount = s[1] - '0';
		totaljobs += amount;
		for(int i = 3; i < s.size() - 1; i++)
		{
			int num = s[i] - '0';
			adj[num].push_back(prnum); adj[prnum].push_back(num);
			capacity[num][prnum] = 1; capacity[prnum][num] = 0;
		}
		adj[prnum].push_back(81);
		capacity[prnum][81] = amount; capacity[81][prnum] = 0;
	}
	
	int flow = max_flow();
	
	if(flow == totaljobs)
	{
		for(int i = 0; i < 10; i++)
		{
			bool allocated = false;
			vector<int> neighs = adj[i];
			for(vector<int>::iterator it = neighs.begin(); it != neighs.end(); it++)
			{
				if(capacity[i][*it] == 0)
				{
					allocated = true;
					cout << (char)(*it + 'A' - 10);
				}
			}
			if(!allocated) cout << "_";
		}
		cout << endl;
	}
	else cout << "!" << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	vector<string> program;
	while(getline(cin, s))
	{
		if(s != "") program.push_back(s);
		else 
		{
			solve(program);
			program.clear();
		}
	}
	solve(program);
}