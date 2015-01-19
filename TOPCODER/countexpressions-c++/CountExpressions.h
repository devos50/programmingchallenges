#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

set<string> resset;

char getop(int n)
{
	if(n == 0) return '+';
	else if(n == 1) return '-';
	else return '*';
}

int retValOp(int x, int op, int y)
{
	if(op == 0) return x + y;
	else if(op == 1) return x - y;
	return x * y;
}

bool solve(int a, int b, int c, int d, int e, int f, int g, int x, int y, int val)
{
	int total = a + c + e + g;
	if(total != x * 2 + y * 2) return false;

	int res = retValOp(a,b,c);
	res = retValOp(res, d, e);
	res = retValOp(res, f, g);
	if(res != val) return false;
	stringstream s; s << a << getop(b) << c << getop(d) << e << getop(f) << g;
	string str = s.str();
	cout << str << endl;
	if(resset.find(str) == resset.end())
	{
		resset.insert(str);
		return true;
	}
	return false;
}

class CountExpressions {

	public: int calcExpressions(int x, int y, int val) {
		int ans = 0;
		for(int a = 0; a < 2; a++)
			for(int b = 0; b < 3; b++)
				for(int c = 0; c < 2; c++)
					for(int d = 0; d < 3; d++)
						for(int e = 0; e < 2; e++)
							for(int f = 0; f < 3; f++)
								for(int g = 0; g < 2; g++)
									if(solve(a % 2 == 0 ? x : y, b, c % 2 == 0 ? x : y,d,e % 2 == 0 ? x : y,f,g % 2 == 0 ? x : y,x,y,val)) ans++;

		return ans;
	}

};
