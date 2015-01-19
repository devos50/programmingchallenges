//
//  main.cpp
//  atwo
//
//  Created by M.A. de Vos on 20-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

void solve()
{
    long int t;
    scanf("%ld", &t);
    
    double a = log2l(t);
    if(t == 0) printf("%d %d\n", 0, 1);
    else if(a == (int)a) printf("%ld\n", t);
    else
    {
        long int v1 = powl(2, (int)a+1);
        printf("%ld %ld\n",t, v1);
    }
}

int main(int argc, const char * argv[])
{
    int tests = 0;
    scanf("%d", &tests);
    for(int i = 0; i < tests; i++) solve();
    
    return 0;
}

