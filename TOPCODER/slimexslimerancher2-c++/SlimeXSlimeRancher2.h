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

class SlimeXSlimeRancher2 {

	public: int train(vector<int> attributes) {

		int max = -1;
		for(int i = 0; i < attributes.size(); i++)
			if(attributes[i] > max) max = attributes[i];

		int ans = 0;
		for(int i = 0; i < attributes.size(); i++) ans += max - attributes[i];

		return ans;
	}

};
