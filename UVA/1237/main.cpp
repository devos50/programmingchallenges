#include <iostream>
#include <map>

using namespace std;

map<string, pair<int, int> > db;

string in_db(int p)
{
	int matches = 0;
	string manufactorer = "";
	for(map<string, pair<int, int> >::iterator it = db.begin(); it != db.end(); it++)
	{
		if(p >= it->second.first && p <= it->second.second) 
		{
			matches++;
			if(matches == 2) { break; }
			manufactorer = it->first;
		}
	}
	
	if(matches == 0 || matches > 1) { return "UNDETERMINED"; }
	
	return manufactorer;
}

void solve()
{
	db.clear();
	int d; cin >> d;
	for(int i = 0; i < d; i++)
	{
		string m; int l, h;
		cin >> m >> l >> h;
		db[m] = make_pair(l, h);
	}
	
	int q; cin >> q;
	for(int i = 0; i < q; i++)
	{
		int price; cin >> price;
		cout << in_db(price) << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		if(i == 0) { solve(); }
		else
		{
			cout << endl;
			solve();
		}
	}
}