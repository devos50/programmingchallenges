#include <iostream>

using namespace std;

bool is_prime(int n) 
{
	if(n == 0) return false;
	else if(n == 1) return true;
	else if(n == 2) return true;
	else if(n % 2 == 0) return false;
	
     for(int i = 3; i * i <= n; i+=2)
         if(n % i == 0) return false;
     return true;
}

int main(int argc, char *argv[]) 
{
	string s;
	while(cin >> s)
	{
		// determine the value
		int val = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] >= 'a' && s[i] <= 'z') { val += s[i] - 'a' + 1; }
			else { val += s[i] - 'A' + 27; }
		}
		
		if(is_prime(val)) cout << "It is a prime word." << endl;
		else cout << "It is not a prime word." << endl;
	}
}