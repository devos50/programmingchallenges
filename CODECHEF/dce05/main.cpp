#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void solve()
{
	int n; scanf("%d", &n);
	printf("%d\n", (int)(pow(2, floor(log2(n)))));
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}