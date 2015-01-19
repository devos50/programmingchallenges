#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	unsigned long long n; cin >> n;
	
	unsigned long long ans = (n * (n + 1) * (2 * n + 1)) / 12 + (n * (n + 1)) / 4;
	
	cout << ans << endl;
}