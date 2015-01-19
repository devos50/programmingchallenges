#include <iostream>
#include <sstream>

using namespace std;

string N = "21780";

bool bouncy(int num)
{
	bool inc = false;
	bool dec = false;
	int last = num % 10;
	num /= 10;
	
	while(num > 0)
	{
		int next = num % 10;
		num /= 10;
		if(next < last) inc = true;
		else if(next > last) dec = true;
		
		last = next;
		if(dec && inc) return true;
	}
	return (dec && inc);
}

int main(int argc, char *argv[]) 
{
	int i = 99;
	int bouncies = 0;
	
	while(100 * bouncies < 99 * i)
	{
		i++;
		if(bouncy(i)) bouncies++;
	}
	cout << i << endl;
}