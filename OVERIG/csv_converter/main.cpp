#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> get_parts(string s, string delimiter)
{
	vector<string> parts;
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
	    token = s.substr(0, pos);
		parts.push_back(token);
	    s.erase(0, pos + delimiter.length());
	}
	parts.push_back(s);
	return parts;
}

int main(int argc, char *argv[]) 
{
	fstream fin("artikelen.csv");
	string s;
	while(getline(fin, s))
	{
		vector<string> parts = get_parts(s, ";");
		string nummer = parts[0];
		string leverancier = parts[1];
		string artikelnummer = parts[2];
		string omschrijving = parts[3];
		string prijs = parts[4];
		int voorraad = 0;
		int mutatie = 0;
		string aantekening = parts[7];
		cout << "INSERT INTO artikelen VALUES('" << nummer << "', '" << artikelnummer << "', '" << omschrijving << "', '" << voorraad << "', '" << aantekening << "', '" << leverancier << "', '" << prijs << "');" << endl;
	}
}