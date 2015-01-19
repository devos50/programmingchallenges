#include <iostream>

using namespace std;

string binary(unsigned x)
{
    char buffer[64];
    char* p = buffer + 64;
    do
    {
        *--p = '0' + (x & 1);
    } while (x >>= 1);
    return string(p, buffer + 64);
}

void solve(int t)
{
	string bin = binary(t);
	int sum = 0;
	for(int i = 0; i < bin.size(); i++)
		if(bin[i] == '1') sum++;
	
	cout << "The parity of " << bin << " is " << sum << " (mod 2)." << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t != 0)
	{
		solve(t);
		
		cin >> t;
	}
}