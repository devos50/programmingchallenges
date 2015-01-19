#include <iostream>
#include <cstdio>

using namespace std;

void solve()
{
	int n; cin >> n;
	int grades[n];
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> grades[i];
		sum += grades[i];
	}
	
	int r = 0;
	for(int i = 0; i < n; i++)
		if(grades[i] * n > sum) r++;
		
	printf("%.3f%%\n", 100.0 * r / n);
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}