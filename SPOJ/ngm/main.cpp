#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s;
	while(cin >> s)
	{
		if(s.at(s.size() - 1) != '0') cout << "1" << endl << s.at(s.size() - 1);
		else cout << "2" << endl;
	}
}