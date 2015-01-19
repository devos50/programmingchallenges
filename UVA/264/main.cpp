#include <iostream>
#include <cstdio>

using namespace std;

void solve(int n)
{
    int c = n;
    int d = 0;
    // get diagonal number
    while(c > 0)
    {
        d++;
        c -= d;
    }
    c += d;
    
    if(d % 2 != 0)
    {
        printf("TERM %i IS %i/%i\n", n, d - c + 1, c);
    }
    else
    {
        printf("TERM %i IS %i/%i\n", n, c, d - c + 1);
    }
}

int main(int argc, const char * argv[])
{
	int n;
	while(cin >> n) solve(n);
    return 0;
}

