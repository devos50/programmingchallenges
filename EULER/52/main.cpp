#include <iostream>
#include <sstream>

using namespace std;

bool samedigits(int num1, int num2)
{
	stringstream ss1, ss2; ss1 << num1; ss2 << num2;
	string s1, s2; s1 = ss1.str(); s2 = ss2.str();
	int freq1[9], freq2[9];
	for(int i = 0; i < 10; i++) freq1[i] = freq2[i] = true;
	
	for(int i = 0; i < s1.size(); i++) freq1[s1.at(i) - '0']++;
	for(int i = 0; i < s2.size(); i++) freq2[s2.at(i) - '0']++;
	
	for(int i = 0; i < 9; i++)
		if(freq1[i] != freq2[i]) return false;
	return true;
}

int main(int argc, char *argv[]) 
{
	int cur = 1;
	while(true)
	{
		if(samedigits(cur, cur * 2) && samedigits(cur * 2, cur * 3) && samedigits(cur * 3, cur * 4) && samedigits(cur * 4, cur * 5) && samedigits(cur * 5, cur * 6))
		{
			cout << cur << endl;
			break;
		}
		cur++;
	}
}