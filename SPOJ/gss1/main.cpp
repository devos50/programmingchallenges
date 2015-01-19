#include <iostream>
#include <cmath>
#include <cstdio>

#define INF -1000000000

using namespace std;

int T[100000];

void update(int node, int s, int e, int id, int value)
{
	if(id < s || id > e || s > e)
		return;
		
	if(s == e)
	{
		T[node] = value;
		return;
	}
	
	update(node * 2, s, (s + e) / 2, id, value);
	update(node * 2 + 1, (s + e) / 2 + 1, e, id, value);
	
	T[node] = max(T[node * 2], T[node * 2 + 1]);
}

int query(int node, int s, int e, int S, int E)
{
	if(s > E || e < S || s > e)
		return INF;
	
	if(s >= S && e <= E) 
		return T[node];
		
	return max(query(node * 2, s, (s + e) / 2, S, E), query(node * 2 + 1, (s + e) / 2 + 1, e, S, E));
}

int main(int argc, char *argv[]) 
{
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int num; scanf("%d", &num);
		update(1, 0, n - 1, i, num);
	}
	
	int q; scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int l, r; scanf("%d %d", &l, &r);
		if(l == 0 && r == 0) { printf("%d\n",query(1, 0, n - 1, l, r)); continue; }
		l--; r--;
		printf("%d\n", query(1, 0, n - 1, l, r));
	}
}