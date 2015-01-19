#include <iostream>

using namespace std;

void solve()
{
	int f; cin >> f;
	int res = 0;
	for(int i = 0; i < f; i++)
	{
		int opp; cin >> opp;
		int anims; cin >> anims;
		int last; cin >> last;
		res += opp * last;
	}
	cout << res << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}