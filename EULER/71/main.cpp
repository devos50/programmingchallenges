#include <iostream>
#include <algorithm>
#include <vector>

#define D 1000000

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[]) 
{
	double diff = 1000.0;
	int thenum, thedenum;
	for(int denum = 1; denum <= D; denum++)
	{
		int num = (double)(denum * 3) / 7.0;
		if(denum % 7 == 0) num--;
		if(3.0 / 7.0 - (double)num / (double)denum < diff)
		{
			diff = 3.0 / 7.0 - (double)num / (double)denum;
			thenum = num;
			thedenum = denum;
		}
	}
	cout << thenum << "/" << thedenum << endl;
}