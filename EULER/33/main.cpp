#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	for(int num = 10; num <= 99; num++)
	{
		for(int denum = num + 1; denum <= 99; denum++)
		{
			// cout << num << "/" << denum << endl;
			if(num / 10 == denum % 10)
			{
				// if(num % 10 == denum / 10) cout << num << "/" << denum << endl;
			}
			if(num % 10 == denum / 10)
			{
				if(denum % 10 == 0) continue;
				if((double)num / (double)denum == ((double)(num / 10) / (double)(denum % 10))) cout << num << "/" << denum << endl;
			}
		}
	}
}