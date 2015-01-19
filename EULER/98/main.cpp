#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

set<string> words;
map<int, vector<string> > letter_map;
map<string, vector<string> > anagrams_hash;
map<string, vector<string> > square_numbers_hash;
int ans = -1;

bool is_anagram(string s1, string s2)
{
	int freq[26]; for(int i = 0; i < 26; i++) freq[i] = 0;
	for(int i = 0; i < s1.length(); i++) freq[s1[i] - 'A']++;
	
	for(int i = 0; i < s2.length(); i++)
	{
		int c = s2[i] - 'A';
		if(freq[c] == 0) return false;
		freq[c]--;
	}
	return true;
}

bool numbers_are_anagram(string s1, string s2)
{
	int freq[10]; for(int i = 0; i < 10; i++) freq[i] = 0;
	for(int i = 0; i < s1.length(); i++) freq[s1[i] - '0']++;
		
	for(int i = 0; i < s2.length(); i++)
	{
		int c = s2[i] - '0';
		if(freq[c] == 0) return false;
		freq[c]--;
	}
	return true;
}

bool check_mapping(string a1, string a2, string n1, string n2)
{
	map<char, char> c_map; // bijv. c => 1
	map<char, char> rev_map; // bijv. 1 => c
	for(int i = 0; i < a1.size(); i++)
	{
		if(rev_map.find(n1[i]) != rev_map.end() && rev_map[n1[i]] != a1[i])
		{
			return false;
		}
		else
		{
			c_map[a1[i]] = n1[i];
			rev_map[n1[i]] = a1[i];
		}
	}
	
	string s = "";
	for(int i = 0; i < a2.size(); i++)
		s += c_map[a2[i]];
		
	return (s == n2);
}

void check_anagrams(string a1, string a2)
{
	// cout << a1 << ", " << a2 << endl;
	
	for(map<string, vector<string> >::iterator it = square_numbers_hash.begin(); it != square_numbers_hash.end(); it++)
	{
		if(it->first.size() != a1.size()) continue;
		vector<string> v = it->second;
		for(vector<string>::iterator it2 = v.begin(); it2 != v.end(); it2++)
		{
			for(vector<string>::iterator it3 = v.begin(); it3 != v.end(); it3++)
			{
				if(*it2 == *it3) continue;
				if(check_mapping(a1, a2, *it2, *it3))
				{
					// cout << "found a mapping of the pair (" << a1 << ", " << a2 << ") with (" << *it2 << ", " << *it3 << ")" << endl;
					int n1 = atoi((*it2).c_str());
					int n2 = atoi((*it3).c_str());
					if(n1 > ans) ans = n1;
					if(n2 > ans) ans = n2;
				}
			}
		}
	}
}

int main(int argc, char *argv[]) 
{
	fstream fin("words.txt");
	string s; fin >> s;
	
	string delim = ",";

	auto start = 0U;
	auto end = s.find(delim);
	while (end != std::string::npos)
	{
		string str = s.substr(start, end - start);
		str = str.substr(1, str.length() - 2);
		words.insert(str);
		letter_map[str.length()].push_back(str);
		
	    start = end + delim.length();
	    end = s.find(delim, start);
	}

	string str = s.substr(start, end);
	str = str.substr(1, str.length() - 2);
	words.insert(str);
	letter_map[str.length()].push_back(str);
	
	// find the square numbers
	for(int i = 1; i <= 31622; i++)
	{
		int num = i * i;
		stringstream ss; ss << num; string s = ss.str();
		
		sort(s.begin(), s.end());
		square_numbers_hash[s].push_back(ss.str());
	}
	
	// hash the words
	for(set<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		string cur = *it;
		sort(cur.begin(), cur.end());
		anagrams_hash[cur].push_back(*it);
	}
	
	// find anagrams
	for(map<string, vector<string> >::iterator it = anagrams_hash.begin(); it != anagrams_hash.end(); it++)
	{
		vector<string> v = it->second;
		for(vector<string>::iterator it2 = v.begin(); it2 != v.end(); it2++)
		{
			for(vector<string>::iterator it3 = v.begin(); it3 != v.end(); it3++)
			{
				if(*it2 == *it3) continue;
				check_anagrams(*it2, *it3);
			}
		}
	}
	cout << ans << endl;
}