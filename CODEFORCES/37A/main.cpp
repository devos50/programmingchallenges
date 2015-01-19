#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int arr[1005]; for(int i = 0; i < 1005; i++) arr[i] = 0;
	for(int i = 0; i < n; i++)
	{
		int k; cin >> k;
		arr[k]++;
	}
	
	int res = 0, maxn = 0;
	for(int i = 0; i < 1005; i++)
	{
		if(arr[i] != 0) res++;
		if(arr[i] > maxn) maxn = arr[i];
	}
	cout << maxn << " " << res << endl;
}