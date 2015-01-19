#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

vector<string> words;

class AWordGame {

	void parseWords(vector<string> wordList)
	{
		string delim = " ";
		string part;
		for(int i = 0; i < wordList.size(); i++)
		{
			istringstream iss(wordList[i]);
			while(iss >> part) words.push_back(part);
		}
	}

	string minimax(string soFar)
	{
		cout << "SOFAR: " << soFar << endl;
		string ret = string();
		bool branched[256]; for(int i = 0; i < 256; i++) branched[i] = false;
		for(int i = 0; i < words.size(); i++)
		{
			string w = words[i];
			if(w == soFar) return "";
			else if(w.substr(0, soFar.size()) == soFar)
			{
				char ch = w.at(soFar.size());
				if(branched[ch]) continue;
				branched[ch] = true;
				string s = ch + minimax(w.substr(0, soFar.size() + 1));

				if(s.size() % 2 == 0)
				{
					if(ret == string() || ret.size() % 2 == 1 || s.size() < ret.size())
						ret = s;
				}
				else if(ret == string() || (ret.size() % 2 == 1 && s.size() > ret.size()))
				{
				    ret = s;
				}
			}
		}
		return ret;
	}

	public: string outcome(vector<string> wordList) {
		parseWords(wordList);
		sort(words.begin(), words.end());
		string s = minimax("");
		cout << "S: " << s << endl;
		return s;
	}

};
