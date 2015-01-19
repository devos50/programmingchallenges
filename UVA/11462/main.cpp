#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(int n)
{
	vector<int> vec;
	for(int i = 0; i < n; i++)
	{
		int val; cin >> val;
		vec.push_back(val);
	}
	sort(vec.begin(), vec.end());
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it;
		if(it + 1 != vec.end()) cout << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		
		solve(n);
	}
}