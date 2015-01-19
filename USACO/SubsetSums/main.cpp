/*
 ID: mdmarti1
 PROG: subset
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n;
int cumsum[45];
long long memo[820][40];

long long subsets(int leftsum, int cur)
{
	if(memo[leftsum][cur] != -1) return memo[leftsum][cur];
	
	int rightsum = cumsum[cur - 1] - leftsum;
	if(cur == n + 1)
	{
		if(leftsum == rightsum) return 1;
		else return 0;
	}
	
	long long ans = subsets(leftsum + cur, cur + 1) + subsets(leftsum, cur + 1);
	memo[leftsum][cur] = ans;
	return ans;
}

int main()
{
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");

	fin >> n;
	
	// clear memo table
	for(int i = 0; i < 820; i++)
		for(int j = 0; j < 40; j++)
			memo[i][j] = -1;
	
	cumsum[0] = 0;
	for(int i = 1; i <= n; i++) cumsum[i] = cumsum[i - 1] + i;
	// cout << "sum: " << cumsum[40] << endl;
	
	if(cumsum[n] % 2 == 1) fout << 0 << endl;
	else fout << subsets(0, 1) / 2 << endl; 

    return 0;
}