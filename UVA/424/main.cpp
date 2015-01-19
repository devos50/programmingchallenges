#include <iostream>
#include <sstream>

using namespace std;

string addNums(string a, string b)
{
	// add leading zeros
	if(a.size() > b.size())
	{
		int leadZeros = a.size() - b.size();
		for(int i = 0; i < leadZeros; i++) b = "0" + b;
	}
	else if(b.size() > a.size())
	{
		int leadZeros = b.size() - a.size();
		for(int i = 0; i < leadZeros; i++) a = "0" + a;
	}
	
	// add the numbers
	string resstr = "";
	int carry = 0;
	for(int i = b.size() - 1; i >= 0; i--)
	{
		int res = carry + (int)(a.at(i) - '0') + (int)(b.at(i) - '0');
		if(res >= 10) { carry = 1; res -= 10; }
		else carry = 0;
		
		stringstream s; s << res; resstr = s.str() + resstr;
	}
	if(carry == 1) resstr = "1" + resstr;
	// cout << a << " + " << b + " = " << resstr << endl;
	return resstr;
}

int main(int argc, char *argv[]) 
{
	int y = 0;
	string res; cin >> res;
	while(true)
	{
		string b; cin >> b;
		if(b.compare("0") == 0) break;
		res = addNums(res, b);
	}
	cout << res << endl;
}