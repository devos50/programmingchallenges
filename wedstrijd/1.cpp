#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s1; cin >> s1;
	int as1 = s1.length() - 1;
	
	string s; cin >> s;
	int as = s.length() - 1;
	
	if(as <= as1) cout << "go" << endl;
	else cout << "no" << endl;
	
	return 0;
}