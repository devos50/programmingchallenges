#include <iostream>
#include <vector>
#include <map>

using namespace std;

void lis(vector<int> v)
{
	int dp[v.size()];
	int maxLength = 0;
	dp[0] = 1;
	
	for(int i = 1; i < v.size(); i++)
	{
		dp[i] = 1;
		for(int j = i - 1; j >= 0; j--)
		{
			if(v[j] < v[i] && dp[j] >= dp[i]) dp[i] = dp[j] + 1;
		}
	}
	
	// cout << "dp: ";
	for(int i = 0; i < v.size(); i++)
	{
		// cout << dp[i] << " ";
		if(dp[i] > maxLength) maxLength = dp[i];
	}
	// cout << endl;	
	
	cout << maxLength << endl;
}

int main(int argc, char *argv[]) 
{
	int size; cin >> size;
	int correct[size];
	vector<vector<int> > students;
	// read correct line
	for(int i = 0; i < size; i++) { cin >> correct[i]; correct[i]--; }
	
	int t;
	while(cin >> t)
	{
		vector<int> v;
		v.push_back(t-1);
		for(int i = 1; i < size; i++)
		{
			int n; cin >> n;
			v.push_back(n-1);
		}
		students.push_back(v);
	}
	
	int correctevents[size];
	for(int i = 0; i < size; i++) correctevents[correct[i]] = i;
	
	// convert numbers
	map<int, int> cmap;
	for(int i = 0; i < size; i++)
	{
		cmap[correctevents[i]] = i;
		correctevents[i] = i;
	}
	
	for(vector<vector<int> >::iterator it1 = students.begin(); it1 != students.end(); it1++)
	{
		vector<int> v = *it1;
		
		// convert this vector
		int newv[size];
		for(int i = 0; i < size; i++) newv[v[i]] = i;
		v.clear();
		for(int i = 0; i < size; i++) v.push_back(newv[i]);
		
		for(vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
			*it2 = cmap[*it2];
			
		*it1 = v;
	}
	
	// find the longest increasing subsequence
	for(vector<vector<int> >::iterator it = students.begin(); it != students.end(); it++) lis(*it);
}