#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s, t; cin >> s >> t;
	reverse(s.begin(), s.end());
	if(t == s) cout << "YES" << endl;
	else cout << "NO" << endl;
}