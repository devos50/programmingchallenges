#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> nums;

bool check_num(long long n)
{
	while(n != 0)
	{
		int dig = n % 10; n /= 10;
		if(dig != 0 && dig != 1 && dig != 4 && dig != 9) return false;
	}
	return true;
}

void solve()
{
	long long a, b; cin >> a >> b;
	
	int ans = 0;
	for(vector<long long>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		long long num = *it;
		if(num >= a && num <= b) ans++;
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	// preprocess
	for(long long i = 1; i <= 100000; i++)
	{
		long long sq = i * i;
		if(check_num(sq)) { nums.push_back(sq); }
	}
	
	int t; cin >> t;
	while(t--) solve();
}