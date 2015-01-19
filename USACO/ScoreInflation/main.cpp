/*
 ID: mdmarti1
 PROG: inflate
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minutes, categories;
vector<pair<int, int> > catos;

int main()
{
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    
	fin >> minutes >> categories;
	int weight[categories], points[categories];
	
	for(int i = 0; i < categories; i++)
	{
		fin >> points[i] >> weight[i];
	}
	
	int a[minutes+5];
	a[0] = 0;
	for(int i = 0; i <= minutes; i++) a[i] = 0;
	
	for(int i = 1; i <= minutes; i++)
	{
		for(int j = 0; j < categories; j++)
		{
			if(weight[j] <= i && a[i] < a[i - weight[j]] + points[j])
			{
				a[i] = a[i - weight[j]] + points[j];
			}
		}
	}
	fout << a[minutes] << endl;

    return 0;
}