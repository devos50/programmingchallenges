#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s; cin >> s;
	int maxadj = 0;
	int curadj = 0;
	for(int i = 0; i < s.size() - 1; i++)
	{
		if(s[i] == s[i+1]) curadj++;
		else
		{
			if(curadj > maxadj) maxadj = curadj;
			curadj = 0;
		}
	}
	
	if(maxadj >= 6 || curadj >= 6) cout << "YES" << endl;
	else cout << "NO" << endl;
}