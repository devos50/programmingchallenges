#include <iostream>
#include <algorithm>

using namespace std;

string toBinary(long long n)
{
	if(n == 0) return "0";
	string s;
	while(n != 0)
	{
		if(n % 2 == 0) s.push_back('0');
		else s.push_back('1');
		n /= 2;
	}
	reverse(s.begin(), s.end());
	
	string front = "";
	int toplace = 32 - s.size();
	for(int i = 0; i < toplace; i++) front.push_back('0');
	
	return front + s;
}

int toInt(string s)
{
	int curmul = 1;
	int res = 0;
	for(int i = 31; i >= 0; i--)
	{
		if(s.at(i) == '1') res += curmul;
		curmul *= 2;
	}
	return res;
}

void solve(long long n1, long long n2)
{
	string b1 = toBinary(n1), b2 = toBinary(n2);
	// cout << b1 << endl;
	// cout << b2 << endl;
	
	string result = "";
	for(int i = 31; i >= 0; i--)
	{
		if(b1.at(i) == '0' && b2.at(i) == '0') result = "0" + result;
		else if(b1.at(i) == '1' && b2.at(i) == '1') result = "0" + result;
		else result = "1" + result;
	}
	cout << toInt(result) << endl;
}

int main(int argc, char *argv[]) 
{
	long long n1, n2;
	while(cin >> n1 && cin >> n2)
	{
		solve(n1, n2);
	}
}