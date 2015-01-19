#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) 
{
	int t = 50000;
	for(int i = 0; i < t; i++)
	{
		cout << rand() % 100000 + 1 << " " << rand() % 1000 + 1 << endl;
	}
}