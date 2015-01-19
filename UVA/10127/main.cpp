#include <iostream>

using namespace std;

void solve(int n)
{
	int c = 0;
	int m = n;
	while(m != 0)
	{
		m = (m * 10 + 1) % n;
		c++;
	}
	cout << c << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n) solve(n);
}