#include <iostream>
#include <set>
#include <sstream>

using namespace std;

void solve(int n)
{
	if(n == 1)
	{
		cout << "    1  DEFICIENT" << endl;
		return;
	}
	
	int currentupper = n;
	set<int> factors;
	factors.insert(1);
	for(int i = 2; i < currentupper; i++)
	{
		if(n % i == 0)
		{
			currentupper = n / i;
			factors.insert(i);
			if(currentupper != i) factors.insert(currentupper);
		}
	}
	
	int sum = 0;
	for(set<int>::iterator it = factors.begin(); it != factors.end(); it++) sum += *it;
	stringstream s; s << n; string res = s.str();
	for(int i = res.size(); i < 5; i++) res = " " + res;
	if(sum > n) cout << res << "  ABUNDANT" << endl;
	else if(sum < n) cout << res << "  DEFICIENT" << endl;
	else cout << res << "  PERFECT" << endl;
}

int main(int argc, char *argv[]) 
{
	cout << "PERFECTION OUTPUT" << endl;
	while(true)
	{
		int n; cin >> n;
		if(n == 0) break;
		solve(n);
	}
	cout << "END OF OUTPUT" << endl;
}