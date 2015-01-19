#include <iostream>

#define N 168
#define M 50

using namespace std;

long long memo[N+5][N+5];

long long rec(long long cur, long long reds)
{
	if(memo[cur][reds] != -1) return memo[cur][reds];
	
	if(cur == N) return 1;
	
	long long a = rec(cur + 1, 0);
	long long b = 0;
	if(N - cur >= M && reds == 0) b = rec(cur + M, M);
	long long c = 0;
	if(reds >= M) c =rec(cur + 1, reds + 1);
	
	memo[cur][reds] = a + b + c;
	return a + b + c;
}

int main(int argc, char *argv[]) 
{
	for(int y = 0; y < N + 5; y++)
		for(int x = 0; x < N + 5; x++)
			memo[y][x] = -1;
	
	cout << rec(0, 0);
}
