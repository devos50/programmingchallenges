#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve(string s)
{
	map<char, int> freq;
	for(int i = 0; i < s.size(); i++)
		if((s.at(i) >= 'A' && s.at(i) <= 'Z') || (s.at(i) >= 'a' && s.at(i) <= 'z')) freq[s.at(i)]++;
		
	int maxfreq = -1;
	for(map<char, int>::iterator it = freq.begin(); it != freq.end(); it++)
		if(it->second > maxfreq) maxfreq = it->second;
		
	vector<char> letters;
	for(map<char, int>::iterator it = freq.begin(); it != freq.end(); it++)
			if(it->second == maxfreq) letters.push_back(it->first);
	sort(letters.begin(), letters.end());
	
	for(vector<char>::iterator it = letters.begin(); it != letters.end(); it++)
		cout << *it;
	cout << " " << maxfreq << endl;
}

int main(int argc, char *argv[]) 
{
	string s;
	while(getline(cin, s)) solve(s);
}