//
//  main.cpp
//  canton
//
//  Created by M.A. de Vos on 26-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>

using namespace std;

void solve()
{
    int n = 0; scanf("%d", &n);
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
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

