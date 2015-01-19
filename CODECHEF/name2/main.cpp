#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
	string name1, name2; cin >> name1 >> name2;
	
	// name1 subsequence of name2?
	int curc = 0;
	for(int i = 0; i < name2.size(); i++)
	{
		if(name2[i] == name1[curc]) curc++;
		if(curc == name1.size()) break;
	}
	if(curc == name1.size()) { cout << "YES" << endl; return; }
	
	// name2 subsequence of name1?
	swap(name1, name2);
	
	curc = 0;
	for(int i = 0; i < name2.size(); i++)
	{
		if(name2[i] == name1[curc]) curc++;
		if(curc == name1.size()) break;
	}
	if(curc == name1.size()) { cout << "YES" << endl; return; }
	
	cout << "NO" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}