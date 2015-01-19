#include <iostream>

using namespace std;

void solve(int t)
{
	int sum = 0;
	int a, b; cin >> a; cin >> b;
	for(int i = a; i <= b; i++)
		if(i % 2 != 0) sum += i;
		
	cout << "Case " << t << ": " << sum << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}