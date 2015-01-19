#include <iostream>

using namespace std;

int count(int s[], int m, int n)
{
	int table[n+1];
	for(int i = 0; i < n + 1; i++) table[i] = 0;
	table[0] = 1;
	
	for(int i = 0; i < m; i++)
	 	for(int j = s[i]; j <= n; j++)
			table[j] += table[j - s[i]];
	
	return table[n];
}

int main(int argc, char *argv[]) 
{
	int arr[] = {50, 25, 10, 5, 1};
	int m = 5;
	int n;
	while(cin >> n)
	{
		cout << count(arr, m, n) << endl;
	}
}