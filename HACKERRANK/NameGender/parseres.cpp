#include <iostream>
#include <fstream>
#include <map>

using namespace std;
int main(int argc, char *argv[]) 
{
	cout << "map<string, int> genders;";
	
	ifstream fin("out.txt");
	
	string s;
	while(getline(fin, s))
	{
		cout << s << endl;
	}
}