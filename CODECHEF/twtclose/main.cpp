#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k; cin >> n >> k;
	bool open[n]; for(int i = 0; i < n; i++) open[i] = false;
	
	int numOpen = 0;
	for(int i = 0; i < k; i++)
	{
		string cmd; cin >> cmd;
		if(cmd == "CLICK")
		{
			int twtnum; cin >> twtnum;
			twtnum--;
			if(!open[twtnum])
			{
				open[twtnum] = true;
				numOpen++;
			}
			else
			{
				open[twtnum] = false;
				numOpen--;
			}
		}
		else if(cmd == "CLOSEALL")
		{
			for(int i = 0; i < n; i++) open[i] = false;
			numOpen = 0;
		}
		cout << numOpen << endl;
	}
}