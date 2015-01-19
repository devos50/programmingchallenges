//
//  main.cpp
//  coins
//
//  Created by M.A. de Vos on 01-12-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstdlib>
#include <math.h>

using namespace std;

map<int, long long> h;

long long f(int n)
{
    if(n == 0) return 0;
    
    long long r = h[n];
    if(r == 0)
    {
        long long r1 = f(n/2)+f(n/3)+f(n/4);
        if(r1 > n) r = r1;
        else r = n;
        h[n] = r;
    }
    return r;
}

void solve(int n)
{
    h.clear();
    printf("%lld\n", f(n));
}

int main(int argc, const char * argv[])
{
    int t = 0;
    scanf("%d", &t);
    while(t != EOF)
    {
        solve(t);
        scanf("%d", &t);
    }
    return 0;
}

