/*
 ID: mdmarti1
 PROG: lamps
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <map>

#define MAXN 105

using namespace std;

char finalconf[MAXN];
int N, C;
set<string> seen;
set<string> resset;

ofstream fout ("lamps.out");
ifstream fin ("lamps.in");

bool isGoodState(string s)
{
	// check consistence with finalconf
	for(int i = 0; i < N; i++)
		if(s[i] != finalconf[i] && finalconf[i] != '2') return false;
	
	return true;
}

void dfs(string cur, int level)
{
	// cout << "cur: " << cur << endl;
	if(level == C + 1) return;
	
	if(isGoodState(cur)) resset.insert(cur);
	
	// press button 1
	string res = "";
	for(int i = 0; i < cur.size(); i++)
		res.push_back(cur[i] == '0' ? '	1' : '0');
	
	if(seen.find(res) == seen.end())
	{
		seen.insert(res);
		dfs(res, level + 1);
		seen.erase(seen.find(res));
	}
		
	res = "";
	// press button 2
	for(int i = 0; i < cur.size(); i++)
	{
		if(i % 2 == 1) res.push_back(cur[i] == '0' ? '1' : '0');
		else res.push_back(cur[i]);
	}
	
	if(seen.find(res) == seen.end())
	{
		seen.insert(res);
		dfs(res, level + 1);
		seen.erase(seen.find(res));
	}
		
	res = "";
	// press button 3
	for(int i = 0; i < cur.size(); i++)
	{
		if(i % 2 == 0) res.push_back(cur[i] == '0' ? '1' : '0');
		else res.push_back(cur[i]);
	}
		
	if(seen.find(res) == seen.end())
	{
		seen.insert(res);
		dfs(res, level + 1);
		seen.erase(seen.find(res));
	}
				
	res = "";
	// press button 4
	for(int i = 0; i < cur.size(); i++)
	{
		if(i % 3 == 0) res.push_back(cur[i] == '0' ? '1' : '0');
		else res.push_back(cur[i]);
	}
	
	if(seen.find(res) == seen.end())
	{
		seen.insert(res);
		dfs(res, level + 1);
		seen.erase(seen.find(res));
	}
}
int main()
{
	fin >> N >> C;
	for(int i = 0; i < N; i++) finalconf[i] = '2';
	
	// read final config - ON
	while(true)
	{
		int curn; fin >> curn;
		if(curn == -1) break;
		finalconf[curn - 1] = '1';
	}
	// read final config - OFF
	while(true)
	{
		int curn; fin >> curn;
		if(curn == -1) break;
		finalconf[curn - 1] = '0';
	}

	// make the beginstate
	string begin = ""; for(int i = 0; i < N; i++) begin.push_back('1');
	seen.insert(begin);
	dfs(begin, 0);
	
	if(resset.size() == 0)
	{
		fout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	// print the final states
	for(set<string>::iterator it = resset.begin(); it != resset.end(); it++)
		fout << *it << endl;

    return 0;
}