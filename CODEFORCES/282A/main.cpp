#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int x = 0;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if(s[0] == '+' || s[2] == '+') x++;
		else if(s[0] == '-' || s[2] == '-') x--;
	}
	cout << x << endl;
}