#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) 
{
	double n, p;
	while(cin >> n >> p)
	{
		cout << fixed << setprecision(0) << pow(p, 1/n) << endl;
	}
}