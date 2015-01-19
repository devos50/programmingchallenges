#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, m; cin >> n >> m;
	vector<int> nums;
	for(int i = 0; i < m; i++)
	{
		int num; cin >> num;
		nums.push_back(num);
	}
	
	int mindiff = 100000000;
	sort(nums.begin(), nums.end());
	
	for(int i = 0; i <= (m - n); i++)
	{
		int diff = nums[i + n - 1] - nums[i];
		if(diff < mindiff) { mindiff = diff; }
	}
	cout << mindiff << endl;
}