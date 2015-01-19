#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s;
	while(true)
	{
		cin >> s;
		if(s == "0") break;
		
		int sum = 0;
		
		bool shouldSub = false;
		for(int i = 0; i < s.size(); i++)
		{
			if(shouldSub) { sum -= s[i] - '0'; }
			else { sum += s[i] - '0'; }
			shouldSub = !shouldSub;
		}
		
		// cout << "sum: " << sum << endl;
		
		if(sum % 11 == 0) cout << s << " is a multiple of 11." << endl;
		else cout << s << " is not a multiple of 11." << endl;
	}
}