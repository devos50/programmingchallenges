#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	if(n <= 2) { cout << "-1" << endl; return 0; }
	for(int i = n; i > 0; i--)
	{
		cout << i << " ";
	}
	cout << endl;
}