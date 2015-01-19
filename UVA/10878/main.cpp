#include <iostream>

using namespace std;

void process(string s)
{
	int ascii_int = 0;
	int pow2 = 128;
	for(int i = 1; i < 10; i++)
	{
		if(i == 6) continue;
		if(s[i] == 'o') ascii_int += pow2;
		pow2 /= 2;
	}
	cout << (char)ascii_int;
}

int main(int argc, char *argv[]) 
{
	string s; getline(cin, s);
	
	while(true)
	{
		getline(cin, s);
		if(s == "___________") break;
		
		process(s);
		
		// cout << s << endl;
	}
}