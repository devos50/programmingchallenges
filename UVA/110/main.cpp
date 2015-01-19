#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int> l;
int lsize;
int n;

void permutations(int arr[], int a, int niv)
{
	if(a < n)
	{
		for(int i = 0; i <= l.size(); i++)
		{
			list<int>::reverse_iterator it = l.rbegin();
			for(int j = 0; j < i; j++) it++;
			
			int opt = 0;
			
			// insert leading spaces
			if(niv != 0)
			{
				for(int i = 0; i < niv; i++) cout << "  ";
							
				if(i == 0 && niv) { cout << "if "; opt = 0; }
				else if(i == l.size()) { cout << "else "; opt = 1; }
				else { cout << "else if "; opt = 2; }
			}
			
			
			l.insert(it.base(), arr[a]);
			
			if(opt != 1)
			{
				it++;
				char c1 = (char)('a' + *it);
				it--;
				char c2 = (char)('a' + *it);
				if(c1 != c2) cout << c1 << " < " << c2;
			}
			
			if(niv != 0)
			{
				if(opt == 0 || opt == 2) cout << " then" << endl;
				else cout << endl;
			}
			
			permutations(arr, a+1, niv+1);
			l.remove(arr[a]);
		}
	}
	else
	{
		for(int i = 0; i < n; i++) cout << "  ";
		cout << "writeln(";
		for(list<int>::iterator it = l.begin(); it != l.end(); it++)
		{
			if((++it)-- == l.end()) cout << (char)('a' + *it) << ")";
			else cout << (char)('a' + *it) << ",";
		}
		cout << endl;
	}
}

void solve()
{
	lsize = 0;
	cin >> n;
	cout << "program sort(input,output);" << endl << "var" << endl;
	
	for(int i = 0; i < n; i++)
	{
		char c = 'a' + i;
		cout << c;
		if(i != n-1) cout << ",";
	}
	cout << " : integer;" << endl << "begin" << endl << "  readln(";
	for(int i = 0; i < n; i++)
	{
		char c = 'a' + i;
		cout << c;
		if(i != n-1) cout << ",";
	}
	cout << ");" << endl;
	
	int v[n];
	for(int i = 0; i < n; i++) v[i] = i;
	permutations(v, 0, 0);
	cout << "end." << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--)
	{
		solve();
		if(t != 0) cout << endl;
	}
}