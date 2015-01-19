/*
 ID: mdmarti1
 PROG: fracdec
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <cstdlib>
#include <map>

using namespace std;

int num, denum;
set<int> seen;
map<int, int> remainders;

int main()
{
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");

	fin >> num >> denum;
	
	string ans = "";
	if(num >= denum)
	{
		int t = num / denum;
		num %= denum;
		stringstream ss; ss << t << ".";
		ans = ss.str();
	}
	else ans = "0.";
	
	if(num == 0)
	{
		fout << ans << "0" << endl;
		return 0;
	}
	
	int rest = num;
	while(true)
	{
		if(rest == 0) // rest = 0, geen repeating digits
		{
			fout << ans << endl;
			return 0;
		}
		
		if(seen.find(rest) != seen.end())
		{
			int pos = remainders[rest];
			ans.insert(pos, 1, '(');
			ans += ")";
			break;
		}
		else // mark it
		{
			seen.insert(rest);
			remainders[rest] = ans.size();
			
			rest *= 10;
			int t = rest / denum;
			rest %= denum;
			stringstream ss; ss << t; ans += ss.str();
		}
	}
	
	int rows = ans.size() / 76;
	for(int i = 0; i < rows; i++)
	{
		fout << ans.substr(i * 76, 76) << endl;
	}
	
	int r = ans.size() % 76;
	fout << ans.substr(rows * 76, ans.size() - rows * 76) << endl;

    return 0;
}