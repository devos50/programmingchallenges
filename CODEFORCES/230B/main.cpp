#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
	if(n == 0 || n == 1) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	for(int i = 3; i * i <= n; i+=2)
	{
		if(n % i == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		long long s; cin >> s;
		double sq = sqrt(s);
		if(sq == (int)sq)
		{
			if(is_prime((int)sq)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
}