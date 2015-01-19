#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

void solve(string s)
{
	s.erase(remove( s.begin(), s.end(),' '), s.end());
	
	// find the = sign
	int equalsIndex = 0;
	while(s.at(equalsIndex) != '=' && equalsIndex != s.size()) equalsIndex++;
	string outcome = s.substr(equalsIndex+1, s.size());
	
	// find the + sign and split
	int plusIndex = 0;
	while(s.at(plusIndex) != '+' && plusIndex != s.size()) plusIndex++;
	string leftPart = s.substr(0, plusIndex);
	string rightPart = s.substr(plusIndex + 1, equalsIndex - (plusIndex + 1));
	
	// is the machula in the outcome?
	if(outcome.find("machula") != string::npos)
	{
		int iLeftPart = atoi(leftPart.c_str()), iRightPart = atoi(rightPart.c_str());
		int iOutcome = iLeftPart + iRightPart;
		cout << iLeftPart << " + " << iRightPart << " = " << iOutcome << endl; 
	}
	// is the machula in the left part?
	if(leftPart.find("machula") != string::npos)
	{
		int iOutcome = atoi(outcome.c_str()), iRightPart = atoi(rightPart.c_str());
		int iLeftPart = iOutcome - iRightPart;
		cout << iLeftPart << " + " << iRightPart << " = " << iOutcome << endl; 
	}
	// is the machula in the right part?
	if(rightPart.find("machula") != string::npos)
	{
		int iOutcome = atoi(outcome.c_str()), iLeftPart = atoi(leftPart.c_str());
		int iRightPart = iOutcome - iLeftPart;
		cout << iLeftPart << " + " << iRightPart << " = " << iOutcome << endl; 
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	string s;
	getline(cin, s);
	while(t--)
	{
		getline(cin, s); getline(cin, s);
		solve(s);
	}
}