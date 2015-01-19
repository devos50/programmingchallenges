#include <iostream>
#include <sstream>

using namespace std;

void solve()
{
	string s; cin >> s;
	if(s.size() <= 10) cout << s << endl;
	else
	{
		stringstream ss; ss << s[0]; ss << s.size() - 2; ss << s[s.size() - 1];
		cout << ss.str() << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	while(n--) solve();
}