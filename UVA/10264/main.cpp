#include <iostream>

using namespace std;

int weights[1 << 15];
int sums[1 << 15];

void solve(int n)
{
	
	for(int i = 0; i < 1 << n; i++)
		cin >> weights[i];
	for(int i = 0; i < 1 << n; i++)
		sums[i] = 0;
		
	// determine potency of every corner
	for(int i = 0; i < 1 << n; i++)
	{
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			int neigh = i ^ (1 << j);
			sum += weights[neigh];
		}
		sums[i] = sum;
	}
	
	// find max potency sum
	int curmax = -1;
	for(int i = 0; i < 1 << n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int neigh = i ^ (1 << j);
			int newsum = sums[i] + sums[neigh];
			if(newsum > curmax) curmax = newsum;
		}
	}
	cout << curmax << endl;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n) solve(n);
}