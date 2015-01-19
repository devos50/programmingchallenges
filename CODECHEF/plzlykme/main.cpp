#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) 
{
	long long n; cin >> n;
	while(n--)
	{
		long long l, d, s, c; cin >> l >> d >> s >> c;
		long double milexp = log2(l);
		// cout << "milexp: " << milexp << endl;
		
		// convert the outcome of the formula likes on day n = s*(c + 1)^n
		long double newbase = log2(c + 1);
		newbase *= (double)(d - 1.0);
		
		long double s_exp = log2(s);
		// cout << "s_exp: " << s_exp << ", newbase: " << newbase << endl;
		long double finalexp = s_exp + newbase;
		
		if(finalexp >= milexp) cout << "ALIVE AND KICKING" << endl;
		else cout << "DEAD AND ROTTING" << endl;
	}
}