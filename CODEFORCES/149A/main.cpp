#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	int k; cin >> k;
	vector<int> nums;
	for(int i = 0; i < 12; i++)
	{
		int n; cin >> n;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end());
	
	int cur = 0; int months = 0;
	for(int i = 11; i >= 0; i--)
	{
		if(cur >= k) break;
		cur += nums[i]; months++;
	}
	
	if(cur < k) cout << "-1" << endl;
	else cout << months << endl;
}