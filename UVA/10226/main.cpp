#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

void solve()
{
	string s;
	int species = 0;
	map<string, int> freq;
	while(true)
	{
		getline(cin, s);
		
		if(s == "") break;
		species++;
		if(freq.find(s) == freq.end()) freq[s] = 1;
		else freq[s]++;
	}
	
	for(map<string, int>::iterator it = freq.begin(); it != freq.end(); it++) 
	{
		string str = it->first;
		printf("%s %.4f\n", str.c_str(), (double)it->second / (double)species * 100);
	}
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	string s;
	for(int i = 0; i < t; i++)
	{
		getline(cin, s);
		getline(cin, s);
		solve();
		if(i != t - 1) cout << endl;
	}
}