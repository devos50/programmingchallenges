#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long n; cin >> n;
	vector<long long> nums; for(int i = 0; i < n; i++) { int s; cin >> s; nums.push_back(s); }
	
	sort(nums.begin(), nums.end());
	
	long long moves = 0;
	for(long long i = 0; i < n; i++)
	{
		long long curind = i + 1;
		moves += abs(nums[i] - curind);
		// if(movesneeded > moves) moves = movesneeded;
	}
	cout << moves << endl;
}