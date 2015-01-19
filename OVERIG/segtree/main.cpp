#include <iostream>
#include <cmath>

#define INF 1000000000

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
	
	T[node] = min(T[node * 2], T[node * 2 + 1]);
}

int query(int node, int s, int e, int S, int E)
{
	if(s > E || e < S || s > e)
		return INF;
	
	if(s >= S && e <= E) 
		return T[node];
		
	return min(query(node * 2, s, (s + e) / 2, S, E), query(node * 2 + 1, (s + e) / 2 + 1, e, S, E));
}

int main(int argc, char *argv[]) 
{
	// eerste regel, n = aantal items, q = aantal queries
	// daarna n getallen met de items
	// daarna q regels met op elke regel l en r
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		int num; cin >> num;
		update(1, 0, n, i, num);
	}
	
	for(int i = 0; i < q; i++)
	{
		int l, r; cin >> l >> r;
		l--; r--;
		cout << query(1, 0, n, l, r) << endl;
	}
}