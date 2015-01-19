#include <iostream>
#include <cmath>

#define MAX 1500000

using namespace std;

int main(int argc, char *argv[]) 
{
	for(long long a = 1; a < 1500000; a++)
	{
		if(a % 100 == 0) cout << "a: " << a << endl;
		
		bool cancont = false;
		for(long long b = 1; b <= a; b++)
		{
			double c = sqrt(a * a + b * b);
			if(a + b + c > MAX) 
			{ 
				// cout << "a: " << a << ", b: " << b << ", c: " << c << endl; 
				cancont = true; 
				break; 
			}
			
		}
		if(cancont) { continue; }
	}
}