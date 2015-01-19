/*
 ID: mdmarti1
 PROG: prefix
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> primitives;
string S;

int main()
{
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
	
	string s; fin >> s;
	while(s != ".")
	{
		primitives.push_back(s);
		fin >> s;
	}
	
	string part;
	while(fin >> part)  S += part;
	
	int dp[S.size() + 5];
	for(int i = 0; i < S.size() + 5; i++) dp[i] = 0;
	
	for(int i = 1; i <= S.size(); i++)
	{
		for(vector<string>::iterator it = primitives.begin(); it != primitives.end(); it++)
		{
			string curprim = *it;
			if(i - (int)curprim.size() < 0) continue;
			
			string sub = S.substr(i - curprim.size(), curprim.size());
			if(curprim == sub && dp[i - curprim.size()] == i - curprim.size())
			{
				int newval = dp[i - curprim.size()] + curprim.size();
				dp[i] = max(dp[i], newval);
			}
		}
	}
	
	int m = -1;
	for(int i = 0; i <= S.size(); i++) { if(dp[i] > m) m = dp[i]; }
	fout << m << endl;
	
    return 0;
}