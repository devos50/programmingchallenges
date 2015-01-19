/*
 ID: mdmarti1
 PROG: money
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long V, N;

long long count(long long S[], long long m, long long n)
{
    long long i, j, x, y;
    long long table[n+1][m];

    for (i = 0; i < m; i++)
        table[0][i] = 1;
 
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
            y = (j >= 1) ? table[i][j-1] : 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

int main()
{
    ofstream fout ("money.out");
    ifstream fin ("money.in");

	fin >> V >> N;

	long long arr[V];
	for(long long i = 0; i < V; i++) fin >> arr[i];
	
	fout << count(arr, V, N) << endl;
	return 0;
}