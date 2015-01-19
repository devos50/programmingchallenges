#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s;
	while(cin >> s)
	{
		char last = '-';
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'H' || s[i] == 'W' || s[i] == 'Y')
			{
				last = '-'; 
				continue;
			}
			else if(s[i] == 'B' || s[i] == 'F' || s[i] == 'P' || s[i] == 'V') 
			{ 
				if(last != '1') { cout << '1'; } 
				last = '1';
			}
			else if(s[i] == 'C' || s[i] == 'G' || s[i] == 'J' || s[i] == 'K' || s[i] == 'Q' || s[i] == 'S' || s[i] == 'X' || s[i] == 'Z')
			{
				if(last != '2') { cout << '2'; }
				last = '2';
			}
			else if(s[i] == 'D' || s[i] == 'T')
			{
				if(last != '3') { cout << '3'; }
				last = '3';
			}
			else if(s[i] == 'L')
			{
				if(last != '4') { cout << '4'; }
				last = '4';
			}
			else if(s[i] == 'M' || s[i] == 'N')
			{
				if(last != '5') { cout << '5'; }
				last = '5';
			}
			else if(s[i] == 'R')
			{
				if(last != '6') { cout << '6'; }
				last = '6';
			}
		}
		cout << endl;
	}
}