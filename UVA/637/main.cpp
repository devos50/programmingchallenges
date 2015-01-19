#include <iostream>

using namespace std;

void solve(int n)
{
	cout << "Printing order for " << n << " pages:" << endl;
	int pages = 1 + ((n - 1) / 4);
	int curleft = 4 * pages;
	int curright = 1;
	for(int i = 1; i <= pages; i++)
	{
		cout << "Sheet " << i << ", front: ";
		if(curleft > n) cout << "Blank";
		else cout << curleft;
		cout << ", " << curright << endl;
		curleft--; curright++;
		
		if(curright > n) continue;
		
		cout << "Sheet " << i << ", back : " << curright << ", ";
		if(curleft > n) cout << "Blank" << endl;
		else cout << curleft << endl;
		curleft--; curright++;
	}
}

int main(int argc, char *argv[]) 
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
	}
}