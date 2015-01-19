#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	unsigned long long n; cin >> n;
	
	unsigned long long sum = 0;
	for(unsigned long long i = 1; i <= n; i++)
	{
		sum += (i * (i + 1)) / 2;
	}
	cout << sum << endl;
}