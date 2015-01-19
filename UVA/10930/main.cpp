#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve(int d, int c)
{
	int nums[d];
	for(int i = 0; i < d; i++) cin >> nums[i];
	set<int> sums;
	
	cout << "Case #" << c << ": ";
	for(int i = 0; i < d - 1; i++) cout << nums[i] << " ";
	cout << nums[d-1] << endl;
	
	sums.insert(nums[0] + nums[1]);
	if(nums[1] <= nums[0])
	{
		cout << "This is not an A-sequence." << endl;
		return;
	}
	
	for(int i = 2; i < d; i++)
	{
		if(nums[i] <= nums[i-1] || sums.find(nums[i]) != sums.end())
		{
			cout << "This is not an A-sequence." << endl;
			return;
		}
		
		vector<int> toinsert;
		for(set<int>::iterator it = sums.begin(); it != sums.end(); it++)
			toinsert.push_back(*it + nums[i]);
			
		for(int j = 0; j < i; j++) sums.insert(nums[j] + nums[i]);
			
		for(vector<int>::iterator it = toinsert.begin(); it != toinsert.end(); it++)
			sums.insert(*it);
	}
	
	cout << "This is an A-sequence." << endl;
}

int main(int argc, char *argv[]) 
{
	int d; int c = 1;
	while(cin >> d)
	{
		solve(d, c);
		c++;
	}
}