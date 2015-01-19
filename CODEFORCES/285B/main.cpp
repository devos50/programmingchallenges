#include <iostream>
#include <set>

using namespace std;

set<int> seen;

int main(int argc, char *argv[]) 
{
	int n, s, t; cin >> n >> s >> t;
	t--;
	int perm[n];
	for(int i = 0; i < n; i++) { cin >> perm[i]; perm[i]--; }
	
	int curpos = s - 1;
	int moves = 0;
	while(curpos != t)
	{
		int newpos = perm[curpos];
		if(seen.find(newpos) != seen.end())
		{
			cout << "-1" << endl;
			return 0;
		}
		seen.insert(newpos);
		curpos = newpos;
		moves++;
	}
	cout << moves << endl;
}