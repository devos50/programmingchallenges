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

class SpaceWarDiv2 {

	public: int minimalFatigue(vector<int> magicalGirlStrength, vector<int> enemyStrength, vector<int> enemyCount) {

		int maxstr = -1;
		for(int i = 0; i < magicalGirlStrength.size(); i++)
			if(magicalGirlStrength[i] > maxstr) maxstr = magicalGirlStrength[i];

		for(int i = 0; i < enemyStrength.size(); i++)
			if(enemyStrength[i] > maxstr) return -1;

		int fatigue[magicalGirlStrength.size()];
		for(int i = 0; i < magicalGirlStrength.size(); i++)
				fatigue[i] = 0;

		for(int i = 0; i < enemyStrength.size(); i++)
		{
			for(int j = 0; j < enemyCount[i]; j++)
			{
				int ind = -1;
				for(int k = 0; k < magicalGirlStrength.size(); k++)
				{
					if(magicalGirlStrength[k] >= enemyStrength[i])
						ind = k;
				}
				fatigue[ind]++;
			}
		}

		int maxfat = 0;
		for(int i = 0; i < magicalGirlStrength.size(); i++)
			if(fatigue[i] > maxfat) maxfat = fatigue[i];

		for(int i = 0; i < magicalGirlStrength.size(); i++)
			cout << fatigue[i] << " ";

		return maxfat;
	}

};
