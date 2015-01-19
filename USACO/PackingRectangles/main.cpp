/*
 ID: mdmarti1
 PROG: packrec
 LANG: C++
 */

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int l, w, rw, rl, best = 10000000;
vector<vector<int> > rect;
set<pair<int, int> > ans;

#define L(i) rect[perm[i]][rotate[i] > 0]
#define W(i) rect[perm[i]][1 - (rotate[i]>0)]
#define add(a, b) ans.insert(make_pair(min(a, b), max(a, b)))
#define best(a, b)  if(a*b <= best){ best = a*b; add(a, b); }

#define Max2(a, b) max(a, b)
#define Max3(a, b, c) max(a, max(b, c))
#define Max4(a, b, c, d) max(a, max(b, max(c, d)))

string toBinary(int number)
{
    if (number == 0) return "0";
    if (number == 1) return "1";

    if (number % 2 == 0)
        return toBinary(number / 2) + "0";
    else
        return toBinary(number / 2) + "1";
}

int main() 
{
	ofstream fout("packrec.out");
	ifstream fin("packrec.in");

	for (int i = 0; i < 4; i++) 
	{
		fin >> l >> w;
		vector<int> rec;
		rec.push_back(l), rec.push_back(w), rect.push_back(rec);
	}

	for (int o = 0; o < 16; o++) 
	{	
		string bin = toBinary(o);
		while(bin.size() != 4) bin = "0" + bin;
		char rotate[4]; for(int i = 0; i < 4; i++) rotate[i] = bin.at(i) - '0';
		int perm[4] = {0, 1, 2, 3};
		do 
		{
			rw = W(0) + W(1) + W(2) + W(3), rl = Max4(L(0), L(1), L(2), L(3));
			best(rw, rl);
			rw = Max2(W(0) + W(1) + W(2), W(3)), rl = L(3) + Max3(L(0), L(1), L(2));
			best(rw, rl);
			rw = W(3) + Max2(W(0) + W(1), W(2)), rl = Max2(L(3), L(2) + Max2(L(0), L(1)));
			best(rw, rl);
			rw = W(0) + Max2(W(1), W(2)) + W(3), rl = Max3(L(0), L(1) + L(2), L(3));
			best(rw, rl);
			rw = Max2(W(0), W(1)) + W(2) + W(3), rl = Max3(L(0) + L(1), L(2), L(3));
			best(rw, rl);
			rw = Max2(W(0)+ W(1), W(2)+ W(3)), rl = Max2(L(0) + L(3), L(1)+ L(2));
			if (rw < W(0) + W(2) && rl < L(0) + L(2)) rw = W(0) + W(2);
			if (rw < W(1) + W(3) && rl < L(1) + L(3)) rw = W(1) + W(3);
			best(rw, rl);
		} while (next_permutation(perm, perm + 4));
	}
	
	fout << best << endl;
	for(set<pair<int, int> >::iterator it = ans.begin(); it!=ans.end(); it++)
		if(it->first * it->second==best)
			fout << it->first << " " << it->second << endl;

}