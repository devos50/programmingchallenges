#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> memo;

long long rec(long long num)
{
	if(memo.find(num) != memo.end()) return memo[num];
	
	if(num == 1) return 0;
	
	long long y = num / 2;
	long long z = num - num / 2;
	
	memo[num] = y * z + rec(y) + rec(z);
	return memo[num];
}

void solve()
{
	vector<long long> nums1, nums2;
	long long n; cin >> n;
	
	cout << rec(n) << endl;
	
	/*
	nums1.push_back(n);
	
	bool loop = true;
	long long ans = 0;
	while(nums1.size() > 0)
	{
		nums2.clear();
		
		for(vector<long long>::iterator it1 = nums1.begin(); it1 != nums1.end(); it1++)
		{
			if(*it1 == 1) continue;
			
			long long num = *it1;
			
			long long y, z;
			y = num / 2;
			z = num - num / 2;
			ans += y * z;
			
			if(y != 1) nums2.push_back(y);
			if(z != 1) nums2.push_back(z);
		}
		
		nums1.clear();
		for(vector<long long>::iterator it = nums2.begin(); it != nums2.end(); it++)
			nums1.push_back(*it);
	}
	*/
	// cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}