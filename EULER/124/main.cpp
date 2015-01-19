#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > nums;

int radical(int num)
{
	int n = num;
	set<int> factors;
	for(int i = 2; i <= n / i; i++)
	{
		while(n % i == 0)
		{
			factors.insert(i);
			// cout << "factor: " << i << endl;
			n /= i;
		}
	}
	if(n > 1) 
	{
		// cout << "factor: " << n << endl;
		factors.insert(n);
	}
	
	int rad = 1;
	for(set<int>::iterator it = factors.begin(); it != factors.end(); it++)
	{
		rad *= *it;
	}
	
	return rad;
}

bool pairCompare(const pair<int, int> &a, const pair<int, int> &b) 
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;

}

int main(int argc, char *argv[]) 
{
	for(int i = 1; i <= 100000; i++)
	{
		// cout << "rad: " << radical(i) << endl;
		nums.push_back(make_pair(i, radical(i)));
	}
	sort(nums.begin(), nums.end(), pairCompare);
	
	cout << nums[9999].first << endl;
}