#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long n; cin >> n;
	long long nums[n];
	for(long long i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	
	long long ans = 0;
	for(long long i = 0; i < 30; i++)
	{
		// count the number of nums which has the i'th bit set to 1
		long long sets = 0;
		for(long long j = 0; j < n; j++)
			if(nums[j] & (1 << i)) sets++;
		
		ans += sets * (sets - 1) / 2 * (1 << i);
	}
	cout << ans << endl;
}