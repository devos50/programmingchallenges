#include <iostream>
#include <set>

using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	bool jobs[n + 1]; for(int i = 0; i < n + 1; i++) jobs[i] = false;
	for(int i = 0; i < m; i++)
	{
		int j; cin >> j;
		jobs[j] = true;
	}
	
	bool chef = true;
	set<int> c_tasks, a_tasks;
	for(int i = 1; i <= n; i++)
	{
		if(!jobs[i])
		{
			if(chef) c_tasks.insert(i);
			else a_tasks.insert(i);
			chef = !chef;
		}
	}
	
	// print
	for(set<int>::iterator it = c_tasks.begin(); it != c_tasks.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	for(set<int>::iterator it = a_tasks.begin(); it != a_tasks.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}