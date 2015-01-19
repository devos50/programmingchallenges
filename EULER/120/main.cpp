#include <iostream>

using namespace std;

long long powmod(long long b, long long e, long long m)
{
	long long res = 1; 
	while(e > 0)
	{
		if(e % 2 == 1) res = (res * b) % m;
		e >>= 1;
		b = (b * b) % m;
	}
	return res;
}

int main(int argc, char *argv[]) {
	long long ans = 0;
	for(long long a = 3; a <= 1000; a++) {
		long long max = -1;
		for(long long n = 1; n <= 2 * a; n += 2) {
			long long temp = (powmod(a - 1, n, a * a) + powmod(a + 1, n, a * a)) % (a * a);
			if(temp > max) 
				max = temp;
		}
		ans += max;
	}
	cout << ans << endl;
}