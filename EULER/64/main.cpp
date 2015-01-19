#include <iostream>
#include <cmath>

using namespace std;

bool is_perfect_square(int n) 
{
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

int main(int argc, char *argv[]) 
{
	int ans = 0;
	for(int i = 1; i <= 10000; i++)
	{
		if(is_perfect_square(i)) continue;
		int m0 = 0;
		int d0 = 1;
		int a0 = sqrt(i);
		int mn = m0, dn = d0, an = a0;
		
		int digits = 0;
		while(true)
		{
			mn = dn*an - mn;
			dn = (i - mn*mn) / dn;
			an = (a0 + mn) / dn;
			digits += 1;
			if(an == 2*a0) break;
		}
		if(digits % 2 == 1) ans++;
	}
	cout << ans << endl;
}