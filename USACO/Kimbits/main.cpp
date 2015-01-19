/*
 ID: mdmarti1
 PROG: kimbits
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

long long N, L, I;

using namespace std;

long long memo[32][32];

long long f(long long n, long long l)
{
	if(memo[n][l] != -1) return memo[n][l];
	
	if(n == 0) return 1;
	if(l == 0) return 1;
	
	long long sum = f( n - 1, l) + f(n - 1, l - 1);
	memo[n][l] = sum;
	
	return sum;
}

string ans(long long n, long long l, long long k)
{
	if(n == 0) return "";
	
	if(k > f(n-1, l)) 
	{
		return "1" + ans(n-1, l-1, k - f(n - 1, l));
	}
	else
	{
		return "0" + ans(n-1, l, k);
	}
}

int main()
{
   	ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");

	for(int i = 0; i < 32; i++)
		for(int j = 0; j < 32; j++)
			memo[i][j] = -1;

	fin >> N >> L >> I;
	fout << ans(N, L, I) << endl;

    return 0;
}