#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; scanf("%d", &n);
	vector<int> nums;
	for(int i = 0; i < n; i++)
	{
		int num; scanf("%d", &num);
		nums.push_back(num);
	}
	
	sort(nums.begin(), nums.end());
	for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) printf("%d\n", *it);
}