#include <iostream>

using namespace std;

void digsum(int n)
{
	int a = 5 * n;
	int b = 5;
	
	for(int i = 0; i < 1000; i++)
	{
		if(a >= b)
		{
			a = a - b;
			b += 10;
		}
		else
		{
			a *= 100;
			b /= 10;
			b *= 100;
			b += 5;
		}
		
		cout << "(" << a << ", " << b << ")" << endl;
	}
	
	cout << "b: " << b << endl;
}

int main(int argc, char *argv[]) 
{
	digsum(2);
}