#include <iostream>
#include <cstdio>

using namespace std;

double clean[4005];

int main(int argc, char *argv[]) 
{
	for(int i = 0; i < 4005; i++) clean[i] = 1.0;
	
	int n, g; cin >> n >> g;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < g; j++)
		{
			int id; cin >> id;
			double p; cin >> p;
			clean[id] *= p;
		}
	}
	
	double ans = 0.0;
	for(int i = 0; i < n; i++) ans += (1.0 - clean[i]);
	
	printf("%.6f\n", ans);
}