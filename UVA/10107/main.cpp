#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	vector<int> nums;
	int n;
	while(cin >> n)
	{
		nums.push_back(n);
		sort(nums.begin(), nums.end());
		if(nums.size() % 2 == 0) cout << (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2 << endl;
		else cout << nums[nums.size() / 2] << endl;
	}
}