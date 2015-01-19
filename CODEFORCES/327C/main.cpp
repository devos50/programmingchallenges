#include <iostream>

using namespace std;

string a;

int rec(string cur, int niv)
{
	if(niv == a.size())
	{
		for(int i = cur.size() - 1; i >= 0; i--)
			if(cur[i] == '1')
			{
				if(a[i] == '0' || a[i] == '5') return 1;
				return 0;
			}
		return 0;
	}
	return rec(cur + "0", niv + 1) + rec(cur + "1", niv + 1);
}

int main(int argc, char *argv[]) 
{
	int k; cin >> a >> k;
	cout << rec("", 0);
	
}