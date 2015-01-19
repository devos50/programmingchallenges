//
//  main.cpp
//  prime1
//
//  Created by M.A. de Vos on 20-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

void solve()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    
    int *primes = new int[b-a+1];
    for(int i=0;i<b-a+1;i++)
        primes[i] = 0;
    
    for(int p=2; p*p<=b; p++)
    {
        int less = a / p;
        less *= p;
        
        for(int j=less; j<=b; j+=p) if(j != p && j >= a)
            primes[j - a] = 1;
    }
    
    for(int i=0;i<b-a+1;++i)
    {
        if(primes[i] == 0 && a+i != 1)
            printf("%d\n",a+i);
    }
    
    printf("\n");
}

int main(int argc, const char * argv[])
{
    int t = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) solve();
    
    return 0;
}

