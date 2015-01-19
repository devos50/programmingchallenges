#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int problems, nr_contests;
map<string, int> probs_required;
vector<vector<string> > probs_possible;
vector<string> contests;
int ans = 0;

// max flow
int s, t;
int n; // aantal knopen
map<int, vector<int> > adj;
int capacity[1010][1010];

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
	
	if(from[t] == -1) return 0;
	
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
	return path_cap;
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

void check_subset(vector<string> subset)
{
	adj.clear();
	s = 1000, t = 1001;
	n = 1005;
	
	// calculate the needed flow
	int needed = 0;
	for(vector<string>::iterator it = subset.begin(); it != subset.end(); it++)
		needed += probs_required[*it];
		
	// create the edges from s to the problems with capacity 1
	for(int i = 0; i < problems; i++)
	{
		adj[s].push_back(i);
		capacity[s][i] = 1;
		capacity[i][s] = 0;
	}
	
	// first, create a map from contest -> number for easy lookup
	map<string, int> contest_indexes;
	int curindex = 0;
	for(vector<string>::iterator it = subset.begin(); it != subset.end(); it++)
	{
		string contest = *it;
		contest_indexes[contest] = problems + curindex;
		curindex++;
	}
	
	// create the edges from every problem to the contests
	for(int i = 0; i < problems; i++)
	{
		vector<string> possible_contests = probs_possible[i];
		for(vector<string>::iterator it = possible_contests.begin(); it != possible_contests.end(); it++)
		{
			int ind = contest_indexes[*it];
			adj[i].push_back(ind);
			adj[ind].push_back(i);
			capacity[i][ind] = 1; 
			capacity[ind][i] = 0;
		}
	}
	
	// finally, create edges from the contests to the drain
	for(int i = problems; i < problems + curindex; i++)
	{
		adj[i].push_back(t);
		capacity[i][t] = 1000;
		capacity[t][i] = 0;
	}
	// max flow
	int mf = max_flow();
	if(mf >= needed) ans = subset.size();
}

void solve(int test_ind)
{
	ans = 0;
	contests.clear();
	probs_possible.clear();
	probs_required.clear();
	
	for(int i = 0; i < nr_contests; i++)
	{
		string contest_name;
		int probs;
		cin >> contest_name >> probs;
		contests.push_back(contest_name);
		probs_required[contest_name] = probs;
	}
	
	string s; getline(cin, s);
	for(int i = 0; i < problems; i++)
	{
		getline(cin, s);
		// split the string in spaces
		string buf;
		stringstream ss(s);
		vector<string> tokens;
		while(ss >> buf) tokens.push_back(buf);
		
		probs_possible.push_back(tokens);
	}
	
	// create subsets
	for(int i = 0; i < (1 << nr_contests); i++)
	{
		if(i % 1000 == 0) cout << "i: " << i << endl;
		vector<string> subset;
		for(int j = 0; j < nr_contests; j++)
		{
			if(i & (1 << j)) { subset.push_back(contests[j]); }
		}
		// cout << endl;
		if(subset.size() != 0) check_subset(subset);
	}
	cout << "Case #" << test_ind << ": " << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int test_ind = 1;
	while(true)
	{
		cin >> nr_contests >> problems;
		if(nr_contests == 0 && problems == 0) break;
		solve(test_ind);
		test_ind++;
	}
}