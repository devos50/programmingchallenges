#include <iostream>
#include <map>

using namespace std;

string KEYBOARD[] = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};

int main(int argc, char *argv[]) 
{
	map<char, char> c2cMap;
	for(int i = 0; i < 4; i++)
	{
		string row = KEYBOARD[i];
		for(int i = 1; i < row.size(); i++) c2cMap[row.at(i)] = row.at(i-1);
		c2cMap[' '] = ' ';
	}
	
	string line;
	string output = "";
	while(getline(cin, line))
	{
		for(int i = 0; i < line.size(); i++)
		{
			char c = line.at(i);
			if(c2cMap.find(c) != c2cMap.end())
			{
				output.push_back(c2cMap[c]);
			}
		}
		cout <<  output << endl;
		output = "";
	}
}