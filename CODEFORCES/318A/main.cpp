#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long n, k; cin >> n >> k;
	
	if (n % 2 == 1)
	{
		n = n + 1;
	}
	 
	long long num;
	
	if (k <= n / 2)
	{
		num = (k * 2) - 1;
	}
	else
	{
		num = (k - n / 2) * 2;
	}
	cout << num << endl;
}