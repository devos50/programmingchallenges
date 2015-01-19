/*
 ID: mdmarti1
 PROG: runround
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

long long M;

using namespace std;

bool isRunaround(long long n)
{
	stringstream ss; ss << n; string str = ss.str();
	
	// unique digits and not zero?
	bool seen[10]; for(int i = 0; i < 10; i++) seen[i] = false;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] - '0' == 0) return false;
		else if(seen[str[i] - '0']) return false;
		else seen[str[i] - '0'] = true;
	}
	
	bool marked[10]; for(int i = 0; i < 10; i++) marked[i] = false;
	
	int index = (str[0] - '0') % str.size();
	
	marked[0] = true;
	bool done = false;
	
	while(!done)
	{
		// cout << "index: " << index << endl;
		
		if(!marked[index]) marked[index] = true;
				else return false;
		
		index = (index + (str[index % str.size()] - '0')) % str.size();
		
		// are they all checked?
		bool allchecked = true;
		for(int i = 0; i < str.size(); i++)
			if(!marked[i]) allchecked = false;
			
		if(allchecked && index == 0) done = true;
	}
	return true;
}

int main()
{
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");

	// cout << "111: " << isRunaround(111) << endl;    

	fin >> M;
	long long cur = M + 1;
	while(!isRunaround(cur)) cur++;
	
	fout << cur << endl;
    return 0;
}