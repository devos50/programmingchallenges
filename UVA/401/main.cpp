#include <iostream>

using namespace std;

char revs[] = {'A', '-', '-', '-', '3', '-', '-', 'H', 'I', 'L', '-', 'J', 'M', '-', 'O', '-', '-', '-', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', '-', 'Z', '-', '-', '8', '-' };

bool isPalindrome(string s)
{
	return s == string(s.rbegin(), s.rend());
}

bool isMirror(string s)
{
	if(s.size() == 1)
	{
		char curchar = s.at(0);
		char revChar;
		if(curchar >= '1' && curchar <= '9') revChar = revs[curchar - '0' + 25];
		else revChar = revs[curchar - 'A'];
		return curchar == revChar;
	}
	
	int curindex;
	curindex = s.size() / 2 - 1;
	while(curindex != -1)
	{
		char curleft = s.at(curindex);
		char curright = s.at(s.size() - curindex - 1);
		// cout << "comparing " << curleft << " with " << curright << endl;
		char revChar;
		if(curleft >= '1' && curleft <= '9') revChar = revs[curleft - '0' + 25];
		else revChar = revs[curleft - 'A'];
		// cout << "rev char: " << revChar << endl;
		if(revChar != curright) return false;
		curindex--;
	}
	return true;
}

void solve(string s)
{
	// cout << s << endl;
	bool palindrome = isPalindrome(s);
	bool mirror = isMirror(s);
	
	if(palindrome && mirror) cout << s << " -- is a mirrored palindrome." << endl << endl;
	else if(!palindrome && mirror) cout << s << " -- is a mirrored string." << endl << endl;
	else if(palindrome && !mirror) cout << s << " -- is a regular palindrome." << endl << endl;
	else cout << s << " -- is not a palindrome." << endl << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	while(getline(cin, s)) solve(s);
}