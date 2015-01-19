#include <iostream>

using namespace std;

bool is_lucky(int n)
{
	while(n != 0)
	{
		int dig = n % 10;
		if(dig != 4 && dig != 7) return false;
		n /= 10;
	}
	return true;
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		if(is_lucky(i) && n % i == 0) { cout << "YES" << endl; return 0; }
	}
	cout << "NO" << endl;
}