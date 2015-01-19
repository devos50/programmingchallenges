#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	fstream fin("energy.in");
	ofstream fout("energy.out");
	
	long long n; fin >> n;
	string s; fin >> s;
	long long score = 0; long long ones = 0; long long twos = 0;
	for(int i = 0; i < s.size(); i++)
	{
		long long free = n - ones - 2 * twos;
		
		if(s[i] == '1')
		{
			if(free > 0) ones++;
			else if(twos > 0)
			{
				twos--;
				ones++;
			}
		}
		else if(s[i] == '2')
		{
			if(free > 1) twos++;
		}
		
		score += ones + twos;
	}
	fout << score << endl;
}