/*
 ID: mdmarti1
 PROG: stamps
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<int> stamps;

int main()
{
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");

	fin >> k >> n;
	for(int i = 0; i < n; i++)
	{
		int num; fin >> num;
		stamps.push_back(num);
	}
	
	sort(stamps.begin(), stamps.end());
	
	int maxval = stamps[stamps.size() - 1] * k;
	int dp[maxval+5];
	for(int i = 0; i <= maxval+1; i++) dp[i] = 2100000000;
	dp[0] = 0; // for 0 are 0 stamps needed
	
	for(int i = 0; i < stamps.size(); i++)
	{
		for(int j = 1; j <= maxval; j++)
		{
			if(j - stamps[i] < 0) continue;
			dp[j] = min(dp[j], dp[j - stamps[i]] + 1);
		}
	}
	
	// for(int i = 0; i <= maxval; i++)
	 //  	cout << "i: " << i << ", " << dp[i] << endl;
		
	// cout << "needed for 243: " << dp[243] << endl;
		
	// find the answer
	for(int i = 0; i <= maxval; i++)
	{
		if(dp[i] > k) { fout << i - 1 << endl; return 0; }
	}
	
	fout << maxval << endl;

    return 0;
}