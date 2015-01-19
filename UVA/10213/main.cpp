#include <iostream>

using namespace std;

long long gcd(long long a,long long b)
{
    if (a%b==0) return b;
    else return gcd(b,a%b);
}
 
void Divbygcd(long long &a, long long &b)
{
    long long g=gcd(a,b);
    a/=g;
    b/=g;
}
 
long long C(int n,int k)
{
    long long numerator=1,denominator=1,toMul,toDiv,i;
    if (k>n/2) k=n-k; /* use smaller k */
    for (i=k;i;i--)
    {
        toMul=n-k+i;
        toDiv=i;
        Divbygcd(toMul,toDiv); /* always divide before multiply */
        Divbygcd(numerator,toDiv);
        Divbygcd(toMul,denominator);
        numerator*=toMul;
        denominator*=toDiv;
    }
	return numerator/denominator;
}

void solve()
{
	int n; cin >> n;
	if(n == 0) cout << 1 << endl;
	else if(n == 1) cout << 2 << endl;
	else if(n == 2) cout << 4 << endl;
	else if(n == 3) cout << 8 << endl;
	else cout << C(n,4) + C(n,2) + 1 << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}