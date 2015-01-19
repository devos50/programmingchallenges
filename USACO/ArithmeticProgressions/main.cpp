/*
 ID: mdmarti1
 PROG: ariprog
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Progression {
	int firstelem;
	int diff;
	
	Progression operator <(const Progression &that)
	{
		return that;
	}
	
} Progression;

bool compare(const Progression &a, const Progression &b)
{
	if(a.diff < b.diff || a.diff > b.diff) return a.diff < b.diff;
	else if(a.diff == b.diff) return a.firstelem < b.firstelem;
	return false; 
}

int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    
	int length, ubound;
	fin >> length; fin >> ubound;
	
	vector<int> vNums;
	bool numbers[125001]; for(int i = 0; i < 125001; i++) numbers[i] = false;
	
	for(int p = 0; p <= ubound; p++)
		for(int q = 0; q <= ubound; q++)
		{
			numbers[p*p + q*q] = true;
			vNums.push_back(p*p + q*q);
		}
	sort(vNums.begin(), vNums.end());
			
	int highestnum = 2 * ubound * ubound;
	vector<Progression> progressions;
	
	// find arithmetic progressions
	for(int i = 0; i <= 125001; i++)
	{
		if(!numbers[i]) continue;
		
		for(int diff = 1; diff <= 5000; diff++)
		{
			int cur = i;
			bool valid = true;
			for(int i = 0; i < length - 1; i++)
			{
				cur += diff;
				if(cur > 125000 || !numbers[cur])
				{
					valid = false;
					break;
				}
			}
			
			if(valid)
			{
				Progression p;
				p.firstelem = i;
				p.diff = diff;
				progressions.push_back(p);
			}
		}
	}
	
	if(progressions.size() == 0)
		fout << "NONE" << endl;
	else
	{
		sort(progressions.begin(), progressions.end(), compare);
		for(vector<Progression>::iterator it = progressions.begin(); it != progressions.end(); it++)
		{
			fout << it->firstelem << " " << it->diff << endl;
		}
	}
    
    return 0;
}