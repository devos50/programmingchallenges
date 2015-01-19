#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	fstream fin("base_exp.txt");
	
	double largest = -1.0;
	int ans = -1;
	for(int i = 0; i < 1000; i++)
	{
		long long base, exp;
		
		fin >> base >> exp;
		double d = log10(base) * (double)exp;
		if(d > largest)
		{
			largest = d;
			ans = i + 1;
		}
		// cout << d << endl;
	}
	cout << ans << endl;
}