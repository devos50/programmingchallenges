/*
 ID: mdmarti1
 PROG: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
string numerals[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

string numToRoman(int num)
{
	string result = "";
	for(int i = 0; i < 13; i++)
	{
		while(num >= values[i])
		{
			num -= values[i];
			result += numerals[i];
		}
	}
	return result;
}

int main()
{
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
	
	int n; fin >> n;
	
	// I = 0, V = 1, X = 2, L = 3, C = 4, D = 5, M = 6
	map<char, int> indmap;
	map<int, char> mapback;
	indmap['I'] = 0, indmap['V'] = 1, indmap['X'] = 2, indmap['L'] = 3, indmap['C'] = 4, indmap['D'] = 5, indmap['M'] = 6;
	mapback[0] = 'I', mapback[1] = 'V', mapback[2] = 'X', mapback[3] = 'L', mapback[4] = 'C', mapback[5] = 'D', mapback[6] = 'M';
	
	int freq[7]; for(int i = 0; i < 7; i++) freq[i] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		string str = numToRoman(i);
		// cout << "i: " << i << " => " << str << endl;
		for(int j = 0; j < str.size(); j++)
			freq[indmap[str.at(j)]]++;
	}
	
	for(int i = 0; i < 7; i++)
	{
		if(freq[i] == 0) continue;
		else { fout << mapback[i] << " " << freq[i]; fout << endl; }
	}

    return 0;
}