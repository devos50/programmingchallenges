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

class PrimalUnlicensedCreatures {

	public: int maxWins(int initialLevel, vector<int> grezPower) {

		int curlevel = initialLevel;
		bool defeated[grezPower.size()]; for(int i = 0; i < grezPower.size(); i++) defeated[i] = false;
		bool canDefeat = true;
		while(canDefeat)
		{
			// find a mob to defeat
			for(int i = 0; i < grezPower.size(); i++)
			{
				if(!defeated[i] && grezPower[i] < curlevel)
				{
					defeated[i] = true;
					curlevel += grezPower[i] / 2;
				}
			}

			// see if the monster can defeat someone
			canDefeat = false;
			for(int i = 0; i < grezPower.size(); i++)
			{
				if(!defeated[i] && grezPower[i] < curlevel) canDefeat = true;
			}
		}

		// count the defeated mobs
		int defs = 0;
		for(int i = 0; i < grezPower.size(); i++)
			if(defeated[i]) defs++;

		return defs;
	}

};
