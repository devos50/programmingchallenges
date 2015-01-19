#include <iostream>
#include <cmath>

using namespace std;

void fun(int n)
{
	while(n > 1)
	{
		cout << n << " ";
		if(n % 2 == 0) n = n / 2;
		else n = 3 * n + 3;
	}
}

int main(int argc, char *argv[]) 
{
	long long n; cin >> n;
	double l = log2((double)n);
	if(l == (int)l) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}