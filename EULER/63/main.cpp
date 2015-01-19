#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	int numDigits = 1;
	int ans = 0;
	while(true)
	{
		int i = 1;
		while(true)
		{
			// bereken len(i ^ numDigits)
			int digits = (double)log10(i) * (double)numDigits + 1;
			// cout << i << "^" << numDigits << ": " << digits << endl;
			if(digits == numDigits) ans++;
			if(digits > numDigits) break;
			
			i++;
		}
		
		cout << ans << endl;
		numDigits++;
	}
}