#include <iostream>
#include <cstdio>

#define PI 3.14159265357989

using namespace std;

int main(int argc, char *argv[]) 
{
	while(true)
	{
		double n; cin >> n;
		if(n == 0) break;
		
		double r = n / PI;
		double ans = (PI * r * r) / 2.0;
		printf("%.2f\n", ans);
	}
}