#include <iostream>

using namespace std;

long long pows[32];

string seq(long long n)
{
	string str;
	while(n != 1)
	{
		if(n % 3 == 0)
		{
			n /= 3;
			str.push_back('D');
		}
		else if(n % 3 == 1)
		{
			n = (4 * n + 2) / 3;
			str.push_back('U');
		}
		else
		{
			n = (2 * n - 1) / 3;
			str.push_back('d');
		}
	}
	return str;
}

bool seq_does_begin_with(string begin, long long n)
{
	string s = seq(n);
	if(s.length() < begin.length()) return false;
	/*
	cout << "testing " << n << " whether it begins with " << begin << endl;
	cout << n << " has string " << seq(n) << endl;
	cout << "the substring is " << s.substr(0, begin.length()) << endl;
	*/
	return (s.substr(0, begin.length()) == begin);
}

int main(int argc, char *argv[]) 
{
	pows[0] = 1;
	for(int i = 1; i <= 31; i++)
		pows[i] = pows[i - 1] * 3;
	
	string dest = "UDDDUdddDDUDDddDdDddDDUDDdUUDd";
	string cur = "U";
	long long n = 4; int curchar = 1;
	while(cur.length() != dest.length())
	{
		cur.push_back(dest[curchar]);
		curchar++;
		// cout << "cur: " << cur << endl;
		for(int i = 0; i < 4; i++)
		{
			if(seq_does_begin_with(cur, n)) break;
			n += pows[cur.length() - 1];
		}
	}
	
	string nxt = seq(n);
	while(true)
	{
		n += pows[dest.length()];
		nxt = seq(n);
		
		if(n > 10E14 && nxt.substr(0, dest.length()) == dest) break;
	}
	
	cout << n << endl;
	// cout << seq(n) << endl;
}