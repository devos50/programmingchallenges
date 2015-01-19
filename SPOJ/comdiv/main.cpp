#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int divisors(int x) {
    int limit = x;
    int numberOfDivisors = 1;

    for (int i = 1; i < limit; ++i) {
        if (x % i == 0) {
            limit = x / i;
            if (limit != i) {
                numberOfDivisors++;
            }
            numberOfDivisors++;
        }
    }

    return numberOfDivisors;
}

void solve()
{
	int a, b; cin >> a >> b;
	cout << "HERE" << endl;
	cout << divisors(gcd(a,b)) << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}