#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	fstream fin("arrange.in");
	ofstream fout("arrange.out");
	
	int n; fin >> n;
	int ans = 0;
	bool seen[26]; for(int i = 0; i < 26; i++) seen[i] = false;
	while(n--)
	{
		string s; fin >> s;
		seen[s[0] - 'A'] = true;
	}
	
	for(int i = 0; i < 26; i++)
	{
		if(!seen[i]) break;
		ans++;
	}
	
	fout << ans << endl;
}