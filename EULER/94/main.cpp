#include <iostream>
#include <cmath>

#define N 1000000000

using namespace std;

double area(double a, double b, double c)
{
	// a = b
	if(a == 0 || b == 0 || c == 0) return 0.0;
	return sqrt(b * b - (c / 2.0) * (c / 2.0));
}

int main(int argc, char *argv[]) 
{
	long long ans = 0;
	for(long long i = 1; i < N; i++)
	{
		double ar = area(i, i, i + 1);
		if(abs(ar - round(ar)) < 0.000000001 && i + i + i + 1 <= 1000000000)
		{
			cout << "+1, i: " << i << ", perimeter: " << i + i + (i - 1) << ", area: " << ar << endl;
			ans += i + i + (i - 1);
		}
		
		ar = area(i, i, i - 1);
		if(abs(ar - round(ar)) < 0.000000001 && i + i + i - 1 <= 1000000000)
		{
			cout << "-1, i: " << i << ", perimeter: " << i + i + (i - 1) << ar << endl;
			ans += i + i + (i - 1);
		}
	}
	cout << ans << endl;
}