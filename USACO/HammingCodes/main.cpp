/*
 ID: mdmarti1
 PROG: hamming
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int n, b, d;

string toBinaryString(int n, int length)
{
	string binstr;
	do binstr.push_back('0' + (n & 1));
	while(n >>= 1);
	
	string l; int tofill = length - binstr.size();
	for(int i = 0; i < tofill; i++) l.push_back('0');
		
	reverse(binstr.begin(), binstr.end());
	return l + binstr;
}

int hammingDistance(int n1, int n2)
{
	string strn1 = toBinaryString(n1, b);
	string strn2 = toBinaryString(n2, b);
	
	int hamdist = 0;
	for(int i = 0; i < b; i++)
		if(strn1.at(i) != strn2.at(i)) hamdist++;
	return hamdist;
}

int main()
{
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    
	fin >> n >> b >> d;
	
	vector<int> resset;
	resset.push_back(0);
	for(int i = 1; i < (1 << b); i++)
	{
		// possible?
		int pos = true;
		for(vector<int>::iterator it = resset.begin(); it != resset.end(); it++)
		{
			if(hammingDistance(*it, i) < d)
			{
				pos = false;
				break;
			}
		}
		if(pos) resset.push_back(i);
	}
	
	int rows = n / 10;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			fout << resset[i * 10 + j];
			if(j != 9) fout << " ";
		}
		fout << endl;
	}
	
	int l = n % 10;
	for(int i = 0; i < l; i++)
	{
		fout << resset[rows * 10 + i];
		if(i != l - 1) fout << " ";
	}
	if(l != 0) fout << endl;

    return 0;
}