#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int s[n];
	vector<int> taxis;
	for(int i = 0; i < n; i++) cin >> s[i];
	
	for(int i = 0; i < n; i++)
		if(s[i] == 4 || s[i] == 3) taxis.push_back(s[i]);
	
	int twos = 0;
	for(int i = 0; i < n; i++) if(s[i] == 2) twos++;
	for(int i = 0; i < twos / 2; i++) taxis.push_back(4);
	if(twos % 2 == 1) taxis.push_back(2);
	
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 1)
		{
			bool found = false;
			for(vector<int>::iterator it = taxis.begin(); it != taxis.end(); it++)
			{
				if(*it < 4) { (*it)++; found = true; break; }
			}
			if(!found) taxis.push_back(1);
		}
	}
	cout << taxis.size() << endl;
}