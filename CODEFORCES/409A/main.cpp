#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s1, s2; cin >> s1 >> s2;
	int games = s1.length() / 2;
	
	int t1wins = 0, t2wins = 0;
	
	for(int i = 0; i < s1.length(); i += 2)
	{
		if(s1[i] == '(' && s2[i] == '8') t1wins++;
		else if(s1[i] == '[' && s2[i] == '(') t1wins++;
		else if(s1[i] == '8' && s2[i] == '[') t1wins++;
		
		else if(s2[i] == '(' && s1[i] == '8') t2wins++;
		else if(s2[i] == '[' && s1[i] == '(') t2wins++;
		else if(s2[i] == '8' && s1[i] == '[') t2wins++; 
	}
	
	if(t1wins > t2wins) cout << "TEAM 1 WINS" << endl;
	else if(t1wins < t2wins) cout << "TEAM 2 WINS" << endl;
	else cout << "TIE" << endl;
}