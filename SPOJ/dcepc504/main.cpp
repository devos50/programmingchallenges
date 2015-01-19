//
//  main.cpp
//  dcepc504
//
//  Created by M.A. de Vos on 19-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void solve()
{
    long long int n = 0, k = 0;
    scanf("%llu %llu", &n, &k);
    k--;
    
    long long int index = k;
    bool rev = false;
    
    for(long long i = n; i >= 1; i--)
    {
        if(index % 2 == 1) rev = !rev;
        index /= 2;
    }
    
    if(rev) printf("Female\n\n");
    else printf("Male\n\n");
}

int main(int argc, const char * argv[])
{
    int t = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) solve();
    
    return 0;
}

