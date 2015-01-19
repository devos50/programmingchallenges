#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int vals[n];
	for(int i = 0; i < n; i++)
	{
		int v; cin >> v;
		vals[v-1] = i + 1;
	}
	
	for(int i = 0; i < n - 1; i++) cout << vals[i] << " ";
	cout << vals[n-1] << endl;
}