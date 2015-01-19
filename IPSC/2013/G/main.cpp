#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>

#define LINT 2000000000
#define MLINT -2000000000

using namespace std;

map<pair<int, int>, int> d;
int r, c, xs, ys, xf, yf;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

struct compareDist
 {  
   bool operator()( pair<int, int> l, pair<int, int> r)
   {  
       return d[l] > d[r];
   }  
 };

int longest_path(pair<int, int> s, pair<int, int> t)
{
	// cout << "begin: " << s.first << ", " << s.second << endl;
	for(int x = 1; x <= c; x++)
		for(int y = 1; y <= r; y++)
			d[make_pair(x, y)] = MLINT;
	
	set<pair<int, int> > settled;
	priority_queue<pair<int, int>, vector<pair<int, int> >, compareDist> unsettled;
	unsettled.push(s);
	d[s] = 0;
	
	while(!unsettled.empty())
	{
		pair<int, int> u = unsettled.top(); unsettled.pop();
		settled.insert(u);
		
		// relaxatie van de buren
		for(int i = 0; i < 4; i++)
		{
			pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);
			
			if(v.first > c || v.first < 1 || v.second > r || v.second < 1) continue;
			
			cout << "V: " << v.first << ", " << v.second << endl;
			
			if(settled.find(v) != settled.end()) continue;
			if(d[v] < d[u] + 1)
			{
				d[v] = d[u] + 1;
				unsettled.push(v);
			}
		}
	}
	
	return d[t];
}

void solve()
{
	cin >> r >> c >> xs >> ys >> xf >> yf;
	
	// cout << "xs: " << r << endl;
	
	cout << longest_path(make_pair(xs, ys), make_pair(xf, yf));
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}