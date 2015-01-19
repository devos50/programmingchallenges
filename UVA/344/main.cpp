/*
 ID: mdmarti1
 PROG: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int values[9] = { 100, 90, 50, 40, 10, 9, 5, 4, 1 };
string numerals[9] = { "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i" };

// I = 0, V = 1, X = 2, L = 3, C = 4, D = 5, M = 6
map<char, int> indmap;
map<int, char> mapback;

string numToRoman(int num)
{
	string result = "";
	for(int i = 0; i < 9; i++)
	{
		while(num >= values[i])
		{
			num -= values[i];
			result += numerals[i];
		}
	}
	return result;
}

void solve(int n)
{
	int freq[5]; for(int i = 0; i < 5; i++) freq[i] = 0;
		
	for(int i = 1; i <= n; i++)
	{
		string str = numToRoman(i);
		// cout << "i: " << i << " => " << str << endl;
		for(int j = 0; j < str.size(); j++)
			freq[indmap[str.at(j)]]++;
	}
	
	cout << n << ": ";
	
	string ans;
	for(int i = 0; i < 5; i++)
	{
		stringstream ss; ss << freq[i];
		ans += ss.str();
		ans.push_back(' ');
		ans.push_back(mapback[i]);
		ans += ", ";
	}
	cout << ans.substr(0, ans.size() - 2) << endl;
}

int main()
{
	indmap['i'] = 0, indmap['v'] = 1, indmap['x'] = 2, indmap['l'] = 3, indmap['c'] = 4;
	mapback[0] = 'i', mapback[1] = 'v', mapback[2] = 'x', mapback[3] = 'l', mapback[4] = 'c';
	
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}

    return 0;
}