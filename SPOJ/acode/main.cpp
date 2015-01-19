#include <iostream>

using namespace std;

void solve(string s)
{
	// string length 1:
	if(s.size() == 1)
	{
		cout << 1 << endl;
		return;
	}
	
	long long dp[10000];
	// base case
	dp[0] = 1;
	if(s.at(1) == '0') dp[1] = 1;
	else if(s.at(0) == '1' || (s.at(0) == '2' && s.at(1) - '0' < 7)) dp[1] = 2;
	else dp[1] = 1;
	
	for(int i = 2; i < s.size(); i++)
	{
		// special case
		if(s.at(i) == '0') dp[i] = dp[i-2];
		
		else if(s.at(i-1) == '1' || (s.at(i-1) == '2' && s.at(i) - '0' < 7)) dp[i] = dp[i-1] + dp[i-2];
		else dp[i] = dp[i-1];
	}
	/*
	cout << "dp: ";
	for(int i = 0; i < s.size(); i++) cout << dp[i] << " ";
	cout << endl;
	*/
	cout << dp[s.size() - 1] << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	while(getline(cin, s))
	{
		if(s.size() == 1 && s.at(0) == '0') break;
		solve(s);
	}
}