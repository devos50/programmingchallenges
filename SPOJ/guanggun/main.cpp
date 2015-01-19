#include <iostream>

using namespace std;

void solve(long long int n)
{
	long long int res = (n / 9) * 81 + (n % 9) * (n % 9);
	cout << res << endl;
}

int main(int argc, char *argv[]) 
{
	long long int n;
	while(cin >> n) solve(n);
}