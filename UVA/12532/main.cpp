#include <iostream>

using namespace std;

int N, K;
long values[10005];

#define INF 1000000000

int T[10005];

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
	
	T[node] = T[node * 2] * T[node * 2 + 1];
	cout << "setting " << node << " to " << T[node] << endl;
}

int query(int node, int s, int e, int S, int E)
{
	if(s > E || e < S || s > e)
		return INF;
	
	if(s >= S && e <= E) 
		return T[node];
		
	return query(node * 2, s, (s + e) / 2, S, E) * query(node * 2 + 1, (s + e) / 2 + 1, e, S, E);
}


void solve()
{
	for(int i = 0; i < N; i++) 
	{
		cin >> values[i];
		update(1, 0, N, i, values[i]);
	}
	
	for(int i = 0; i < K; i++)
	{
		char c; cin >> c;
		if(c == 'C')
		{
			long IE, V; cin >> IE >> V;
			update(1, 0, N, IE, V);
			values[IE - 1] = V;
		}
		else
		{
			int I, J; cin >> I >> J;
			int ans = query(1, 0, N, I, J);
			if(ans == 0) cout << "0";
			else if(ans > 0) cout << "+";
			else cout << "-";
		}
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	while(cin >> N >> K) solve();
}