#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

void solve()
{
	long long n; cin >> n;
	long long sum = 0;
	
	long long sqrt_num = sqrt(n);
	
	for(long long i = 1; i <= sqrt_num; i++) sum += n / i;
	sum *= 2;
	sum -= sqrt_num * sqrt_num;
	
	// cout << sum << endl;
	long long denum = n * n;
	
	long long gcd_num = gcd(sum, denum);
	sum /= gcd_num; denum /= gcd_num;
	cout << sum << "/" << denum << endl;
	
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}