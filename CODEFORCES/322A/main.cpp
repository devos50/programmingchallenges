#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, m; cin >> n >> m;
	bool highm = true;
	int curn = 1, curm = 1;
	int ans = 0;
	vector<pair<int, int> > p;
	while(true)
	{
		if(curn == n + 1 || curm == m + 1) break;
		p.push_back(make_pair(curn, curm));
		// cout << curn << " " << curm << endl;
		
		if(highm) curm++;
		else curn++;
		highm = !highm;
	}
	
	if(curn < n)
	{
		for(int i = curn + 1; i <= n; i++) { p.push_back(make_pair(i, 1)); }
	}
	else if(curm < m)
	{
		for(int i = curm + 1; i <= m; i++) { p.push_back(make_pair(1, i)); }
	}
	
	cout << p.size() << endl;
	for(vector<pair<int, int> >::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}