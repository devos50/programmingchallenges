#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int a, int b, int c)
{
	vector<int> nums; nums.push_back(a); nums.push_back(b); nums.push_back(c);
	sort(nums.begin(), nums.end());
	if(nums[0] * nums[0] + nums[1] * nums[1] == nums[2] * nums[2]) cout << "right" << endl;
	else cout << "wrong" << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		int a, b, c; cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;
		solve(a, b, c);
	}
}