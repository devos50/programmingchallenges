#include <iostream>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map<int, vector<int> > adj;
int s, t;
int n;
int capacity[505][505];

typedef struct Pupil {
	int height;
	char sex;
	string musicstyle;
	string favsport;
	int id;
} Pupil;

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

bool match(Pupil f, Pupil m)
{
	if(abs(f.height - m.height) > 40 || f.musicstyle.compare(m.musicstyle) != 0 || f.favsport.compare(m.favsport) == 0) return false;
	return true;
}

void solve()
{
	adj.clear();
	int pupils; cin >> pupils;
	vector<Pupil> males;
	vector<Pupil> females;
	int counter = 0;
	for(int i = 0; i < pupils; i++)
	{
		Pupil p; cin >> p.height >> p.sex >> p.musicstyle >> p.favsport;
		p.id = counter; counter++;
		if(p.sex == 'M') males.push_back(p);
		else females.push_back(p);
	}
	
	s = counter;
	counter++; t = counter;
	n = counter;
	
	// maak verbindingen
	for(vector<Pupil>::iterator fiter = females.begin(); fiter != females.end(); fiter++) // source -> female
	{
		capacity[s][fiter->id] = 1; capacity[fiter->id][s] = 0;
		adj[s].push_back(fiter->id);
	}
	for(vector<Pupil>::iterator miter = males.begin(); miter != males.end(); miter++) // male -> drain
	{
		capacity[miter->id][t] = 1; capacity[t][miter->id] = 0;
		adj[miter->id].push_back(t);
	}
	
	for(vector<Pupil>::iterator fiter = females.begin(); fiter != females.end(); fiter++)
	{
		int femaleid = fiter->id;
		for(vector<Pupil>::iterator miter = males.begin(); miter != males.end(); miter++)
		{
			int maleid = miter->id;
			if(match(*fiter, *miter))
			{
				capacity[femaleid][maleid] = INT_MAX;
				capacity[maleid][femaleid] = 0;
				adj[femaleid].push_back(maleid);
				adj[maleid].push_back(femaleid);
			}
		}
	}
	
	cout << pupils - max_flow() << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}