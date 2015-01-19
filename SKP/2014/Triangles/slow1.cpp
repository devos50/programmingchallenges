#include <iostream>

using namespace std;

long long f(long long n)
{
	if(n == 1) return 1;
	
	return (n*(n + 1)) / 2 + f(n - 1);
}

int main(int argc, char *argv[]) 
{
	long long n; cin >> n;
	cout << f(n) << endl;
}