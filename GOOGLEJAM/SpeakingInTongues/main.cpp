#include <iostream>
#include <string>

using namespace std;

char letters[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

void solve(int tc)
{
	string s;
	getline(cin, s);
	cout << "Case #" << tc << ": ";
	for(int i = 0; i < s.size(); i++)
	{
		if(s.at(i) == ' ') cout << " ";
		else cout << letters[s.at(i) - 'a'];
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	string s; getline(cin, s);
	for(int i = 0; i < t; i++) solve(i+1);
}