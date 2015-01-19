#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int diff_lines(int n)
{
	set<pair<int, int> > s;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int g = gcd(i, j);
			s.insert(make_pair(i / g, j / g));
		}
	}
	return s.size();
}

int main(int argc, char *argv[]) 
{
	for(int i = 1; i < 50; i++)
	{
		cout << "i: " << i << " => " << diff_lines(i) << endl;
	}
}