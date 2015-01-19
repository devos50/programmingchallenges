#include <iostream>
#include <math.h>

using namespace std;

void solve(string s)
{
	long res = 0;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		int k = (s.size() - 1) - i;
		char dig = s.at(i);
		long r = (long) (pow(2, k+1) - 1);
		res += (int)(dig - '0') * r;
	}
	cout << res << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	while(true)
	{
		cin >> s;
		if(s.compare("0") == 0) break;
		solve(s);
	}
}