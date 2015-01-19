#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) 
{
	double x, y; cin >> x >> y;
	if((int)x % 5 == 0 && (x + 0.50) <= y)
		printf("%.2f", y - (x + 0.50));
	else printf("%.2f", y);
}