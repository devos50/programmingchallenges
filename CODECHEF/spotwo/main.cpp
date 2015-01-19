#include <cstdio>

#define MOD 1000000007

using namespace std;

unsigned long long powermod(unsigned long long b, unsigned long long e, unsigned long long m)
{
	unsigned long long res = 1;
	while(e > 0)
	{
		if(e % 2 == 1) res = (res * b) % m;
		e >>= 1;
		b = (b * b) % m;
	}
	return res;
}

unsigned long long to_binary(unsigned long long x)
{
    unsigned long long rem;
    unsigned long long converted = 0;
    unsigned long long multiplicator = 1;

    while (x > 0)
    {
        rem = x % 2;
        x /= 2;
        converted += rem * multiplicator;
        multiplicator *= 10;
    }

    return converted;
}

int main(int argc, char *argv[]) 
{
	int t; scanf("%d", &t);
	while(t--)
	{
		unsigned long long n; scanf("%llu", &n);
		unsigned long long bin = to_binary(n);
		// cout << "bin: " << bin << endl;
		unsigned long long ans = powermod(4, bin, MOD);
		printf("%llu\n", ans);
	}
}