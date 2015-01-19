#include <iostream>
#include <set>
#include <cassert>

using namespace std;

int factorials[10];

void calcFactorials()
{
	factorials[0] = 1;
	for(int i = 1; i < 10; i++) factorials[i] = factorials[i-1] * i;
}

int newnum(int n)
{
	int newn = 0;
	while(n != 0)
	{
		newn += factorials[n % 10];
		n /= 10;
	}
	return newn;
}

void printSet(set<int> s)
{
	cout << "set: ";
	for(set<int>::iterator it = s.begin(); it != s.end(); it++) cout << *it << " ";
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	calcFactorials();
	int ans = 0;
	for(int i = 1; i < 1000000; i++)
	{
		if(i % 10000 == 0) cout << "i: " << i << endl;
		set<int> s; s.insert(i);
		int cur = newnum(i);
		int length = 1;
		while(s.find(cur) == s.end())
		{
			// 	cout << "cur: " << cur << endl;
			assert(cur > 0);
			length++;
			s.insert(cur);
			cur = newnum(cur);
			// printSet(s);
		}
		if(length == 60) ans++;
		// cout << "i: " << i << ", length: " << length << endl;
	}
	
	cout << ans;
}