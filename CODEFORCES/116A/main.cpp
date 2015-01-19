#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int max_cap = 0;
	int curpass = 0;
	for(int i = 0; i < n; i++)
	{
		int in, out; cin >> out >> in;
		curpass -= out;
		curpass += in;
		if(curpass > max_cap) max_cap = curpass;
	}
	cout << max_cap << endl;
}