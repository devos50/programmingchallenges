#include <iostream>
#include <vector>

using namespace std;

inline bool check_overlucky(int n)
{
	bool pos = false;
	while(n != 0)
	{
		int d = n % 10; n /= 10;
		if(d == 4 || d == 7) pos = true;
	}
	return pos;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		int x; cin >> x;
		/*
		// divisors
		int ans = 0;
			
		int limit = x;
		int numberOfDivisors = 1;
		
		for (int i = 1; i < limit; ++i) {
		    if (x % i == 0) {
		        limit = x / i;
		
				if(check_overlucky(i)) ans++;
				if(i * i != x && check_overlucky(x / i)) ans++;
		    }
		}
		cout << "x: " << x << ", " << ans << endl;
		*/
		int ans = 0;
		for(int i = 1; i * i <= x; i++)
		{
			if(x % i == 0)
			{
				if(check_overlucky(i)) ans++;
				if(i * i != x && check_overlucky(x / i)) ans++;
			}
		}
		cout << ans << endl;
	}
}