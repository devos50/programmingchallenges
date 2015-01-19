#include <iostream>

using namespace std;

void solve(string a, string b)
{
	if(a.size() > b.size())
	{
		int diff = a.size() - b.size();
		for(int i = 0; i < diff; i++) b.insert(0, "0");
	}
	else
	{
		int diff = b.size() - a.size();
		for(int i = 0; i < diff; i++) a.insert(0, "0");
	}
	
	int carries = 0;
	int carry = 0;
	for(int i = a.size() - 1; i >= 0; i--)
	{
		int sum = carry + (int)(a.at(i) - '0') + (int)(b.at(i) - '0');
		if(sum > 9)
		{
			carries++;
			carry = sum / 10;
		}
		else carry = 0;
	}
	
	if(carries == 0) cout << "No carry operation." << endl;
	else if(carries == 1) cout << "1 carry operation." << endl;
	else cout << carries << " carry operations." << endl;
}

int main(int argc, char *argv[]) 
{
	string a, b;
	while(true)
	{
		cin >> a; cin >> b;
		if(!a.compare("0") && !b.compare("0")) break;
		else solve(a, b);
	}
}