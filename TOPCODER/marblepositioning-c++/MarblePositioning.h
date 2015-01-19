#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class MarblePositioning {

	double diff(double rad1, double rad2)
	{
		double c = (rad1 + rad2) * (rad1 + rad2);
		double b = (rad1 - rad2) * (rad1 - rad2);
		// cout << "diff between " << rad1 << " and " << rad2 << ": " << sqrt(c - b) << endl;
		return sqrt(c - b);
	}

	double solve(vector<int> radius, string perms)
	{
		double marblesx[radius.size()];
		marblesx[perms[0] - '0'] = 0.0;
		// double curx = 0;
		for(int i = 1; i < radius.size(); i++) // place marble
		{
			double rad1 = (double)radius[perms[i] - '0'];

			double maxx = -1;
			for(int j = i - 1; j >= 0; j--)
			{
				double rad2 = (double)radius[perms[j] - '0'];
				double newx = diff(rad1, rad2) + marblesx[perms[j] - '0'];
				if(newx > maxx) maxx = newx;
			}
			// cout << "marble " << perms[i] - '0' << ": " << maxx << endl;
			marblesx[perms[i] - '0'] = maxx;
		}

		// find the maximum value of x
		double maxx = -1;
		for(int i = 0; i < radius.size(); i++)
			if(marblesx[i] > maxx) maxx = marblesx[i];
		return maxx;
	}

	public: double totalWidth(vector<int> radius) {

		string perms;
		int curx = 0;
		double minx = 1E15;
		for(int i = 0; i < radius.size(); i++) perms.push_back('0' + i);
		do {
			// solve
			double res = solve(radius, perms);
			// cout << "evaluating " << perms << ": " << res << endl;
			if(res < minx) minx = res;

		} while(next_permutation(perms.begin(), perms.end()));

		return minx;
	}

};
