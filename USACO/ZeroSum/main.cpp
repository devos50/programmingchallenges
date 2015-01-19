/*
 ID: mdmarti1
 PROG: zerosum
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <list>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
set<string> resset;

using namespace std;

int evaluate(string str)
{
	// remove spaces
	string::iterator end_pos = remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	
	int res = 0;
	int index = 0;
	string num;
	
	vector<int> numset;
	while(index < str.size())
	{
		while(index < str.size() && str[index] != '+' && str[index] != '-')
		{
			num += str[index];
			index++;
		}
		numset.push_back(atoi(num.c_str()));
		index++;
		num = "";
	}
	
	res = numset[0]; int cur = 1;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == '+')
		{
			res += numset[cur]; cur++;
		}
		else if(str[i] == '-')
		{
			res -= numset[cur]; cur++;
		}
	}
	// cout << "res: " << res << endl;
	return res;
}

void combs(string cur, int lev)
{
	if(lev == N + 1)
	{
		// cout << cur << endl;
		
		// evaluate
		int res = evaluate(cur);
		if(res == 0) resset.insert(cur);
		
		return;
	}
	
	stringstream ss; ss << lev;
	combs(cur + "+" + ss.str(), lev + 1);
	combs(cur + "-" + ss.str(), lev + 1);
	combs(cur + " " + ss.str(), lev + 1);
}

int main()
{
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
    fin >> N;

	// generate combinations
	combs("1", 2);
	
	// print resset
	for(set<string>::iterator it = resset.begin(); it != resset.end(); it++)
		fout << *it << endl;

    return 0;
}