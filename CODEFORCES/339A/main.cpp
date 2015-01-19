#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	vector<int> digits;
	for(int i = 0; i < s.length(); i+= 2)
	{
		int d = s[i] - '0';
		digits.push_back(d);
	}
	sort(digits.begin(), digits.end());
	
	for(int i = 0; i < digits.size(); i++)
	{
		cout << digits[i];
		if(i != digits.size() - 1) cout << "+";
	}
	cout << endl;
}