#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

bool is_palindrome(long long n)
{
	stringstream ss; ss << n;
	string str = ss.str();
	string rev = str; reverse(rev.begin(), rev.end());
	
	return str == rev;
}

int main(int argc, char *argv[]) 
{
	set<long long> nums;
	long long ans = 0;
	for(long long r = 1; r < 10000; r++)
	{
		for(long long l = 1; l <= r; l++)
		{
			long long sum = (r * (r + 1) * (2 * r + 1)) / 6;
			sum -= ((l - 1) * l * (2 * (l - 1) + 1)) / 6;
			if(sum < 100000000 && sum != 0 && is_palindrome(sum) && l != r) 
			{ 
				cout << "sum: " << sum << ", l: " << l << ", r: " << r << endl; 
				nums.insert(sum); 
			}
			// cout << "sum: " << sum << endl;
			// cout << l << " " << r << endl;
		}
	}
	cout << "elements: " << nums.size() << endl;
	
	for(set<long long>::iterator it = nums.begin(); it != nums.end(); it++)
		ans += *it;
		
	cout << "ans: " << ans << endl;
}