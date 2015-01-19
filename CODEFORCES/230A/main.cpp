#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first;
}

int main(int argc, char *argv[]) 
{
	int s, n; cin >> s >> n;
	vector<pair<int, int> > dragons;
	for(int i = 0; i < n; i++)
	{
		int strength, bonus; cin >> strength >> bonus;
		dragons.push_back(make_pair(strength, bonus));
	}
	sort(dragons.begin(), dragons.end(), comp);
	
	for(int i = 0; i < n; i++)
	{
		pair<int, int> curdrag = dragons[i];
		if(curdrag.first >= s)
		{
			cout << "NO" << endl;
			return 0;
		}
		s += curdrag.second;
	}
	cout << "YES" << endl;
}