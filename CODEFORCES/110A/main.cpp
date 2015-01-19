#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	int count = 0;
	for(int i = 0; i < s.size(); i++)
	{
		int dig = s[i] - '0';
		if(dig == 7 || dig == 4) count++;
	}
	if(count == 7 || count == 4) cout << "YES" << endl;
	else cout << "NO" << endl;
}