#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	int freq[10]; for(int i = 0; i < 10; i++) freq[i] = 0;
	
	long long ans = 1;
	
	int questionmarks = 0;
	for(int i = 0; i < s.size(); i++) // count ?
	{
		if(s[i] == '?' && i == 0) ans *= 9;
		else if(s[i] == '?') questionmarks++;
		else if(s[i] >= 'A' && s[i] <= 'J') freq[s[i] - 'A']++;
	}
	
	int digs = 0;
	for(int i = 0; i < 10; i++)
		if(freq[i] != 0) digs++;
	
	bool firstletter = false;
	if(s[0] >= 'A' && s[0] <= 'J')
	{
		firstletter = true;
		ans *= 9;
		digs--;
	}
	
	if(!firstletter) for(int i = 10; i > 10 - digs; i--) ans *= i;
	else for(int i = 9; i > 9 - digs; i--) ans *= i;
	
	// multiply with the question marks
	stringstream ss; ss << ans;
	string str = ss.str();
	cout << str;
	for(int i = 0; i < questionmarks; i++) cout << "0";
	cout << endl;
}