/*
 ID: mdmarti1
 PROG: contact
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int a, b, n;

using namespace std;

map<string, int> freq;

bool comp(string a, string b)
{
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
	
	fin >> a >> b >> n;
	
	string part;
	string str = "";
	while(fin >> part) str += part;
	
	for(int l = a; l <= b; l++) // iterate over length
	{
		if(l > str.size()) continue;
		for(int i = 0; i < str.size() - l + 1; i++) // and iterate over str
		{
			string sub = str.substr(i, l);
			if(freq.find(sub) == freq.end()) freq[sub] = 1;
			else freq[sub]++;
		}
	}
	
	map<int, vector<string> > revmap;
	
	// todo fill rev map
	for(map<string, int>::iterator it = freq.begin(); it != freq.end(); it++)
	{
		if(revmap.find(it->second) == revmap.end())
		{
			vector<string> vec; vec.push_back(it->first);
			revmap[it->second] = vec;
		}
		else revmap[it->second].push_back(it->first);
	}
	
	int counter = 0;
	for(map<int, vector<string> >::reverse_iterator it = revmap.rbegin(); it != revmap.rend(); it++)
	{
		if(counter >= n) continue;
		fout << it->first << endl;
		vector<string> vec = it->second;
		sort(vec.begin(), vec.end(), comp);
		int c = 1;
		for(vector<string>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)
		{
			fout << *it2;
			if(c % 6 == 0 && it2 != vec.end() - 1) fout << endl;
			if(c % 6 != 0 && it2 != vec.end() - 1) fout << " ";
			c++;
		}
		fout << endl;
		counter++;
	}

    return 0;
}