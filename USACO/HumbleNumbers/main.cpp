/*
 ID: mdmarti1
 PROG: humble
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define LINT 2100000000

using namespace std;

int K, N;
int nums[105];
int humble[100005];
map<int, int> ptrs;

int main()
{
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    
	fin >> K >> N;
	for(int i = 0; i < K; i++)
		fin >> nums[i];
		
	// fill ptrs to point at the first element
	for(int i = 0; i < K; i++)
		ptrs[nums[i]] = 0;
		
	humble[0] = 1;
	for(int i = 1; i <= N; i++)
	{
		// calculate the new values
		int newvals[105];
		for(int j = 0; j < K; j++)
			newvals[j] = humble[ptrs[nums[j]]] * nums[j];
			
		// find the minimum
		int minval = LINT;
		for(int j = 0; j < K; j++)
			if(newvals[j] < minval) minval = newvals[j];
		
		humble[i] = minval;
		// increase pointers
		for(int j = 0; j < K; j++)
			if(newvals[j] == minval) ptrs[nums[j]]++;
			
		cout << "number: " << humble[i] << endl;
	}
	
	fout << humble[N] << endl;

    return 0;
}