#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool isPalindrome(long long a, long long b)
{
	int freq1[10], freq2[10];
	for(int i = 0; i < 10; i++) freq1[i] = 0, freq2[i] = 0;
	
	long long cp1 = a, cp2 = b;
	while(cp1 != 0)
	{
		int dig = cp1 % 10;
		cp1 /= 10;
		freq1[dig]++;
	}
	while(cp2 != 0)
	{
		int dig = cp2 % 10;
		cp2 /= 10;
		freq2[dig]++;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(freq1[i] != freq2[i]) return false;
	}
	return true;
}

int main(int argc, char *argv[]) 
{
	vector<long long> cubes;
	for(long long i = 1; i <= 10000; i++)
		cubes.push_back(i * i * i);
		
	for(int i = 0; i < 10000; i++)
	{
		int numcubes = 0;
		vector<long long> pals;
		// iterate over every other element
		for(int j = 0; j < 10000; j++)
		{
			if(i != j && isPalindrome(cubes[i], cubes[j])) { numcubes++; pals.push_back(cubes[j]); }
		}
		if(numcubes == 4)
		{
			cout << "num: " << cubes[i] << endl;
			break;
		}
	}
}