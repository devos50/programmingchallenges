/*
 ID: mdmarti1
 PROG: sprime
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int n;
ofstream fout;
ifstream fin;

bool isPrime(int num)
{
	if(num == 0 || num == 1) return false;
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}

void rec(string s, int niv)
{
	if(niv == n)
	{
		fout << s << endl;
		return;
	}
	
	for(int i = 1; i < 10; i++)
	{
		s.push_back(i + '0');
		int tempnum = atoi(s.c_str());
		if(isPrime(tempnum)) rec(s, niv+1);
		s = s.substr(0, s.size() - 1);
	}
}

int main()
{
	fout.open("sprime.out");
	fin.open("sprime.in");

    fin >> n;

	rec("", 0);

    return 0;
}