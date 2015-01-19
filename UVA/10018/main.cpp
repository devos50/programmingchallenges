#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

bool isPalindrome(long n)
{
	ostringstream convert;
	convert << n;
	string s = convert.str();
	for(int i = s.length() / 2 - 1; i >= 0; i--)
		if(s.at(i) != s.at(s.length() - i - 1)) return false;
	return true;
}

void solve()
{
	long n; cin >> n;
	int c = 0;
	
	while(!isPalindrome(n))
	{
		ostringstream convert;
		convert << n;
		string toRev = convert.str();
		
		c++;
		string s = string(toRev.rbegin(), toRev.rend());
		long li = strtol(s.c_str(), NULL, 10);
		n += li;
	}
	cout << c << " " << n << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}