#include <iostream>
#include <sstream>

using namespace std;

string ans_two[3] = { "00", "01", "81" };
string ans_four[5] = { "0000", "0001", "2025", "3025", "9801" };
string ans_six[5] = { "000000", "000001", "088209", "494209", "998001" };
string ans_eight[9] = { "00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001" };
/*
void solve(int n)
{
	// find the max number
	int max = 1; for(int i = 0; i < n; i++) max *= 10;
	for(int i = 0; i < max; i++)
	{
		stringstream ss; ss << i; string str = ss.str();
		int toAdd = n - str.size();
		for(int j = 0; j < toAdd; j++) str = "0" + str;
		
		string leftStr = str.substr(0, str.size() / 2);
		string rightStr = str.substr(str.size() / 2, str.size() / 2);
		
		int ans = atoi(leftStr.c_str()) + atoi(rightStr.c_str());
		if(ans * ans == i) 
		{
			cout << i << endl;
		}
	}
	cout << "HERE" << endl;
}
*/
int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n)
	{
		if(n == 2)
			for(int i = 0; i < 3; i++) cout << ans_two[i] << endl;
		else if(n == 4)
			for(int i = 0; i < 5; i++) cout << ans_four[i] << endl;
		else if(n == 6)
			for(int i = 0; i < 5; i++) cout << ans_six[i] << endl;
		else if(n == 8)
			for(int i = 0; i < 9; i++) cout << ans_eight[i] << endl;
	}
	// solve(2); cout << "-----" << endl;
	// solve(4); cout << "-----" << endl;
	// solve(6); cout << "-----" << endl;
	// solve(8); cout << "-----" << endl;
}