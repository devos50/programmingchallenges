#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k, l, c, d, p, nl, np; cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int drink = k * l;
	int t_drink = drink / nl;
	int t_limes = c * d;
	int t_salt = p / np;
	
	if(t_drink < t_limes && t_drink < t_salt) cout << t_drink / n << endl;
	else if(t_limes < t_drink && t_limes < t_salt) cout << t_limes / n << endl;
	else cout << t_salt / n << endl;
}