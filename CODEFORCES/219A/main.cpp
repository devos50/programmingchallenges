#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int k; cin >> k;
	string s; cin >> s;
	int freq[26]; for(int i = 0; i < 26; i++) freq[i] = 0;
	
	for(int i = 0; i < s.size(); i++)
		freq[s[i] - 'a']++;
		
	for(int i = 0; i < 26; i++)
	{
		if(freq[i] != 0 && freq[i] % k != 0)
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	
	string a = "";
	for(int i = 0; i < 26; i++)
	{
		if(freq[i] != 0)
		{
			for(int j = 0; j < freq[i] / k; j++) a.push_back('a' + i);
		}
	}
	
	for(int i = 0; i < k; i++) cout << a;
	cout << endl;
}