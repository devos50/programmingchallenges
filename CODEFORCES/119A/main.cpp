#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[]) 
{
	int a, b, n; cin >> a >> b >> n;
	bool simon_on_turn = true; 
	int should_take = (simon_on_turn) ? gcd(a, n) : gcd(b, n);
	while(should_take <= n)
	{
		// cout << "taking " << should_take << endl;
		simon_on_turn = !simon_on_turn;
		n -= should_take;
		should_take = (simon_on_turn) ? gcd(a, n) : gcd(b, n);
	}
	
	if(simon_on_turn) cout << "1" << endl;
	else cout << "0" << endl;
}