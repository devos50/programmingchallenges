#include <iostream>
#include <set>

using namespace std;

void solve(int cas)
{
	long long a, b, c; cin >> a >> b >> c;
	
	if(!(a + b > c && a + c > b && b + c > a)) cout << "Case " << cas << ": Invalid" << endl;
	
	else if(a == b && b == c) cout << "Case " << cas << ": Equilateral" << endl;
	else if(a == b || b == c || a == c) cout << "Case " << cas << ": Isosceles" << endl;	else cout << "Case " << cas << ": Scalene" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve(i + 1);
}