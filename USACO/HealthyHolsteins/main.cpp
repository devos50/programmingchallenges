/*
 ID: mdmarti1
 PROG: holstein
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> ans;

bool isSmaller(vector<int> resset)
{
	for(int i = 0; i < resset.size(); i++)
		if(resset[i] < ans[i]) return true;
	return false;
}

int main()
{
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
	
	int v, g;
	fin >> v;
	int req[v];
	for(int i = 0; i < v; i++) fin >> req[i];
	fin >> g;
	int feedInfo[g][v];
	
	for(int i = 0; i < g; i++)
		for(int j = 0; j < v; j++)
			fin >> feedInfo[i][j];
			
	int minsize = 100000;
	for(int i = 0; i < 20; i++) ans.push_back(20);
	
	for(int i = 0; i < (1 << g); i++)
	{
		bool num[g];
		for(int j = 0; j < g; j++)
			num[j] = i & (1 << j);
		
		// possible?
		int food[v]; for(int j = 0; j < v; j++) food[j] = 0;
		for(int j = 0; j < g; j++)
		{
			if(num[j])
				for(int k = 0; k < v; k++) food[k] += feedInfo[j][k];
		}
		
		// enough vitamines to take?
		bool pos = true;
		for(int j = 0; j < v; j++)
			if(food[j] < req[j]) pos = false;
		
		if(pos)
		{
			vector<int> resset;
			for(int j = 0; j < g; j++)
				if(num[j]) resset.push_back(j + 1);
			
			if(resset.size() < minsize)
			{
				minsize = resset.size();
				ans = resset;
			}
			else if(resset.size() == minsize && isSmaller(resset))
			{
				ans = resset;
			}
		}
	}
	
	fout << ans.size() << " ";
	for(int i = 0; i < ans.size(); i++)
	{
		fout << ans[i];
		if(i != ans.size() - 1) fout << " ";
	}
	fout << endl;

    return 0;
}