#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	string h = "hello";
	int curind = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == h[curind]) curind++;
		if(curind == h.size()) break;
	}
	
	if(curind == h.size()) cout << "YES" << endl;
	else cout << "NO" << endl;
}