#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		if(i < k) // swap elements
		{
			cout << i * 2 + 2 << " " << i * 2 + 1;
		}
		else
			cout << i * 2 + 1 << " " << i * 2 + 2;
		
		if(i != n - 1) cout << " ";
	}
}