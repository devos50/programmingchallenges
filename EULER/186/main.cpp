#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

int parent[1000005];
int size[1000005];
int rank[1000005];
int dp[10000005];

void fills()
{
	for(int i = 1; i <= 55; i++)
	{
		long long ans = (100003 - 200003 * (long long)i + 300007 * (long long)i * (long long)i * (long long)i) % 1000000;
		dp[i] = ans;
	}
	for(int i = 56; i <= 10000005; i++)
	{
		long long ans = (dp[i - 24] + dp[i - 55]) % 1000000;
		dp[i] = ans;
	}
}

int find(int n)
{
	if(parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int x, int y)
{
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	if(rank[rx] > rank[ry]) swap(rx, ry);
	size[ry] += size[rx];
	parent[rx] = parent[ry];
	rank[ry] = max(rank[ry], rank[rx] + 1);
}

int main(int argc, char *argv[]) 
{
	// initialize the union find data structure
	for(int i = 0; i < 1000005; i++)
	{
		parent[i] = i, size[i] = 1;
	}
	
	int calls = 0;
	int i = 1;
	fills();
	while(true)
	{
		int caller = dp[2*i-1];
		int called = dp[2*i];
		if(caller == called) {i++; continue; }
		else 
		{
			calls++;
			merge(caller, called);
		}
		
		if(size[parent[524287]] >= 990000)
		{
			cout << calls;
			break;
		}
		i++;
	}
}