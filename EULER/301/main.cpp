#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long ans = 0;
	for(long long i = 0; i <= 1073741824; i++)
	{
		long long a = i; long long b = 2 * i; long long c = 3 * i;
		long long res = a ^ b; res = res ^ c;
		if(res == 0) ans++;
		if(i % 10000000 == 0) cout << "HERE" << endl;
	}
	cout << ans - 1 << endl;
}