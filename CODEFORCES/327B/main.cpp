#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if(n == 0 || n == 1) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	
	for(int i = 3; i * i <= n; i+= 2)
		if(n % i == 0) return false;
	return true;
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int printed = 0;
	int curind = 3;
	while(printed != n)
	{
		if(isPrime(curind)) { cout << curind << " "; printed++; }
		curind++;
	}
	cout << endl;
}