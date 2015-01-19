#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) 
{
	vector<int> textnums;
	ifstream fin("cipher1.txt");
	string text; fin >> text;
	char ctext[text.size()];
	for(int i = 0; i < text.size(); i++) ctext[i] = text[i];
	
	// split the string into the vector
	const char *p;
	for(p = strtok(ctext, ","); p; p = strtok(NULL, ","))
		textnums.push_back(atoi(p));
	
	for(char c1 = 'a'; c1 <= 'z'; c1++)
		for(char c2 = 'a'; c2 <= 'z'; c2++)
			for(char c3 = 'a'; c3 <= 'z'; c3++)
			{
				string newtext = "";
				char key[3]; key[0] = c1; key[1] = c2; key[2] = c3;
				for(int i = 0; i < textnums.size(); i++)
				{
					int res = textnums[i] ^ (int)(key[i % 3]);
					newtext.push_back((char)res);
				}
				
				// key = god
				if(key[0] == 'g' && key[1] == 'o' && key[2] == 'd')
				{
					int sum = 0;
					for(int i = 0; i < newtext.size() - 1; i++)
						sum += (int)newtext.at(i);
					cout << sum;
					return 0;
				}
			}
}