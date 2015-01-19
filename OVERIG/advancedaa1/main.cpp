#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<pair<int, int> > jobs;

bool pairCompare(const std::pair<int, int>& firstElem, const std::pair<int, int>& secondElem) 
{
  return firstElem.first < secondElem.first;

}

int main(int argc, char *argv[]) 
{
	// read file
	fstream fin("testcase.dat");
	
	int n; fin >> n;
	for(int i = 0; i < n; i++)
	{
		int length; fin >> length;
		int duetime; fin >> duetime;
		jobs.push_back(make_pair(length, duetime));
	}
	
	sort(jobs.begin(), jobs.end(), pairCompare);
	
	// make permutations and calculate answer
	int minans = 10000000;
	do 
	{
		int total = 0;
		int curtime = 0;
		for(int i = 0; i < n; i++)
		{
			curtime += jobs[i].first;
			int toolate = curtime - jobs[i].second;
			if(toolate > 0) { total += toolate; }
			// cout << "(" << jobs[i].first << ", " << jobs[i].second << ") ";
		}
		
		// cout << total << endl;
		if(total < minans) { minans = total; }
	} while(next_permutation(jobs.begin(), jobs.end()));
	
	cout << minans << endl;
}