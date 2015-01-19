/*
 ID: mdmarti1
 PROG: frac1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Fraction {
	int num;
	int denum;
} Fraction;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

bool compare(const Fraction &f1, const Fraction &f2)
{
	if((double)f1.num / (double)f1.denum < (double)f2.num / (double)f2.denum) return true;
	return false;
}

int main()
{
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int n; fin >> n;
	vector<Fraction> fractions;

	Fraction f1, f2; f1.num = 0; f1.denum = 1;
	f2.num = 1; f2.denum = 1;
	fractions.push_back(f1); fractions.push_back(f2);
	
	for(int num = 1; num < n; num++)
	{
		for(int denum = num + 1; denum <= n; denum++)
		{
			int grdiv = gcd(num, denum);
			cout << num << "/" << denum << ", div: " << grdiv << endl;
			if(grdiv == 1 || num == 1)
			{
				Fraction f; f.num = num; f.denum = denum;
				fractions.push_back(f);
			}
		}
	}
	
	sort(fractions.begin(), fractions.end(), compare);
	for(vector<Fraction>::iterator it = fractions.begin(); it != fractions.end(); it++)
	{
		fout << it->num << "/" << it->denum << endl;
	}
	
    return 0;
}