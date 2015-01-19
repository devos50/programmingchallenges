#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	if(n >= 0) { cout << n << endl; return 0; }
	
	// remove last digit
	int ld = n / 10;
	
	// remove one before last digit
	int ld2 = n / 100 * 10 + n % 10;
	
	int max = (ld > ld2) ? ld : ld2;
	cout << max << endl;
}