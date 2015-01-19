#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set<string> words;

int main(int argc, char *argv[]) 
{
	ifstream fin ("corpus.txt");
	string word;
	int count = 0;
	while(fin >> word)
	{
		if(word.size() > 0 && word[0] >= 'A' && word[0] <= 'Z')
		{
			if(word[word.size() - 1] > 'z' || word[word.size() - 1] < 'a') word = word.substr(0, word.size() - 1);
			words.insert(word);
		}
	}
	cout << words.size();
	
	for(set<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		cout << *it << endl;
	}
	cout << words.size() << endl;
}