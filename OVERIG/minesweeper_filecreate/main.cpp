#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	ofstream file("field.txt");
	for(int i = 0; i < 1000000; i++)
	{
		file << rand() % 2;
	}
	
	return 0;
}