#include <iostream>

#define N 500

using namespace std;

long long memo[N+5][N+5];
int m;

long long rec(long long cur, long long reds)
{
	if(memo[cur][reds] != -1) return memo[cur][reds];
	
	if(cur == N) return 1;
	
	long long a = rec(cur + 1, 0);
	long long b = 0;
	if(N - cur >= 2) b += rec(cur + 2, reds + 2);
	if(N - cur >= 3) b += rec(cur + 3, reds + 3);
	if(N - cur >= 4) b += rec(cur + 4, reds + 4);
	
	memo[cur][reds] = a + b;
	return a + b;
}

void reset_memo()
{
	for(int y = 0; y < N + 5; y++)
		for(int x = 0; x < N + 5; x++)
			memo[y][x] = -1;
}

int main(int argc, char *argv[]) 
{
	reset_memo();
	long long ans = 0;
	ans += rec(0, 0);
	
	cout << ans;
}