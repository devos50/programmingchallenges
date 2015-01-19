#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long n;
	while(cin >> n)
	{
		long long row = (n - 1) / 2 + 1;
		long long ans = 6 * row * row - 9;
		cout << ans << endl;
	}
}