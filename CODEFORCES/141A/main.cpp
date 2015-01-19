#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	int freq[26]; for(int i = 0; i < 26; i++) freq[i] = 0;
	
	for(int i = 0; i < s1.size(); i++)
		freq[s1[i] - 'A']++;
	for(int i = 0; i < s2.size(); i++)
		freq[s2[i] - 'A']++;
		
	for(int i = 0; i < s3.size(); i++)
	{
		if(freq[s3[i] - 'A'] == 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		freq[s3[i] - 'A']--;
	}
	
	for(int i = 0; i < 26; i++)
	{
		if(freq[i] != 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}