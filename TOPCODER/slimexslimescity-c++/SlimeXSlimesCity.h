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


class SlimeXSlimesCity {

	public: int merge(vector<int> population) {

		int ans = 0;
		sort(population.begin(), population.end());

		for(int i = 0; i < population.size() - 1; i++)
		{
			cout << "i: " << i << endl;
			long long prevsum = 0;
			for(int j = i - 1; j >= 0; j--)
				prevsum += population[j];
			cout << "prevsum: " << prevsum << endl;

			long long bedVal = prevsum + population[i];
			bool pos = true;
			for(int j = i + 1; j < population.size(); j++)
			{
				if(bedVal < population[j]){ pos = false; break; }
				bedVal += population[j];
			}

			if(pos) ans++;

			// if(prevsum + population[i] >= population[i+1]) { cout << "i = " << i << "possible"; ans++; }
		}

		return ans + 1; // biggest city can always merge
	}

};
