#include <iostream>
#include <set>

using namespace std;

void solve(int n, int p)
{
	set<string> reqs;
	string s; getline(cin, s);
	for(int i = 0; i < n; i++)
	{
		getline(cin, s);
		cout << "S: " << s << endl;
	}
	
	string bestprop;
	double lowestprice = -1;
	
	for(int i = 0; i < p; i++)
	{
		string propname; cin >> propname;
		double d; int r; cin >> d >> r; getline(cin, s);
		int reqs = 0;
		for(int j = 0; j < r; j++)
		{
			getline(cin, s);
			if(reqs.find(s) != reqs.end()) reqs++;
		}
	}
}

int main(int argc, char *argv[]) 
{
	int n, p;
	while(true)
	{
		cin >> n >> p;
		if(n == 0 && p == 0) break;
		solve(n, p);
	}
}