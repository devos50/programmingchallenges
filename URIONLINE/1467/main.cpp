#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int a, b, c;
	while(cin >> a >> b >> c)
	{
		if(a == 0 && b == 0 && c == 0) { cout << "*" << endl; }
		else if(a == 1 && b == 1 && c == 1) { cout << "*" << endl; }
		else
		{
			if(a != b && a != c) { cout << "A" << endl; }
			else if(b != a && b != c) { cout << "B" << endl; }
			else if(c != a && c != b) { cout << "C" << endl; }
		}
	}
}