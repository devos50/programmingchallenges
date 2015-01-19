#include <iostream>

using namespace std;

void solve(string s)
{
	int cursum = 0;
	for(int i = 0; i < s.size(); i++)
	{
		// check if it is a number
		if(s.at(i) >= '0' && s.at(i) <= '9') cursum += (s.at(i) - '0');
		else if(s.at(i) == 'b')
		{
			for(int j = 0; j < cursum; j++) cout << " ";
			cursum = 0;
		}
		else if(s.at(i) == '!') { cout << endl; cursum = 0; }
		else if(s.at(i) == '\n') { cout << endl; cursum = 0; }
		else
		{
			for(int j = 0; j < cursum; j++) cout << s.at(i);
			cursum = 0;
		}
	}
	
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	bool first = true;
	while(getline(cin, s))
	{
		if(!first) cout << endl;
		else first = false;
		while(true)
		{
			string snew;
			getline(cin, snew);
			if(snew != "") s = s + '\n' + snew;
			else break;
		}
		solve(s);
	}
}