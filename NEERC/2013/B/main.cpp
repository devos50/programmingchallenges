#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

map<string, int> candidates_map;
map<string, int> c_index;
vector<string> candidates;

bool compare_pairs(const pair<string, double> &p1, const pair<string, double> &p2)
{
	string c1 = p1.first, c2 = p2.first;
	if(candidates_map[c1] == candidates_map[c2])
	{
		if(c_index[c1] < c_index[c2]) return true;
		else return false;
	}
	return p1.second > p2.second;
}

double round(double x)
{
   double y = 100 * x;
   int rounded = (int)(y + 0.5);
	return (double)rounded / 100.0;
}

int main(int argc, char *argv[]) 
{
	fstream fin("bad.in");
	ofstream fout("bad.out");
	
	int n, m; fin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		string c; fin >> c;
		candidates_map[c] = 0;
		c_index[c] = i;
		candidates.push_back(c);
	}
	
	int invalid = 0;
	
	for(int i = 0; i < m; i++)
	{
		int crosses = 0;
		string s; fin >> s;
		
		// check valid
		for(int i = 0; i < n; i++)
			if(s[i] == 'X') crosses++;
			
		if(crosses == 0 || crosses > 1) invalid++;
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(s[i] == 'X') { candidates_map[candidates[i]]++; }
			}
		}
	}
	
	// calculate the result
	vector<pair<string, double> > percentages;
	for(map<string, int>::iterator it = candidates_map.begin(); it != candidates_map.end(); it++)
	{
		double p = 100.0 * (double)(it->second) / (double)m;
		// cout << it->first << " " << p << endl;
		percentages.push_back(make_pair(it->first, p));
	}
	
	sort(percentages.begin(), percentages.end(), compare_pairs);
	
	fout << fixed << setprecision(2);
	
	for(vector<pair<string, double> >::iterator it = percentages.begin(); it != percentages.end(); it++)
	{
		pair<string, double> pair = *it;
		fout << pair.first << " " << round(pair.second) << "%" << endl;
	}
	
	double invalid_p = 100.0 * (double)invalid / (double)m;
	fout << "Invalid" << " " << round(invalid_p) << "%" << endl;
}