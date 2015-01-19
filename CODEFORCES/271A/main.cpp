#include <iostream>
#include <set>

using namespace std;

bool unique_digits(int n)
{
	set<int> digs;
	int numdigs = 0;
	while(n != 0)
	{
		int dig = n % 10;
		digs.insert(dig);
		n /= 10;
		numdigs++;
	}
	return (digs.size() == numdigs);
}

int main(int argc, char *argv[]) 
{
	int year; cin >> year;
	year++;
	while(!unique_digits(year)) year++;
	
	cout << year << endl;
}