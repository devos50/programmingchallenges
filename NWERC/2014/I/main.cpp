#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<string, int> verdicts1;
map<string, int> verdicts2;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s1; cin >> s1;
		if(!verdicts1[s1]) { verdicts1[s1] = 1; }
		else { verdicts1[s1]++; }
	}
	for(int i = 0; i < n; i++)
	{
		string s1; cin >> s1;
		if(!verdicts2[s1]) { verdicts2[s1] = 1; }
		else { verdicts2[s1]++; }
	}
	
	int ans = 0;
	for(map<string, int>::iterator it = verdicts1.begin(); it != verdicts1.end(); it++)
	{
		string s = it->first;
		int v = it->second;
		ans += min(v, verdicts2[s]);
	}
	cout << ans << endl;
}