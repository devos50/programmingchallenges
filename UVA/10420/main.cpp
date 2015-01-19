#include <iostream>
#include <map>

using namespace std;

map<string, int> countries;

void solve()
{
	
	string line;
	getline(cin, line);
	string country = "";
	int i = 0;
	while(line.at(i) != ' ') { country.push_back(line.at(i)); i++; }
	
	if(countries.find(country) == countries.end()) countries[country] = 1;
	else countries[country]++;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	string tmp;
	getline(cin, tmp);
	for(int i = 0; i < t; i++) { solve(); }
	
	for(map<string, int>::iterator it = countries.begin(); it != countries.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}