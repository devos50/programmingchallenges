#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	while(n--)
	{
		string s; cin >> s;
		if(s.find("010") != string::npos || s.find("101") != string::npos)
			cout << "Good" << endl;
		else
			cout << "Bad" << endl;
	}
}