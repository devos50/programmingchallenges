//
//  main.cpp
//  acpc11b
//
//  Created by M.A. de Vos on 03-12-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

void solve()
{
    int n1, n2;
    scanf("%d", &n1);
    int alts1[n1];
    for(int i = 0; i < n1; i++) scanf("%d", &alts1[i]);
    
    scanf("%d", &n2);
    int alts2[n2];
    for(int i = 0; i < n2; i++) scanf("%d", &alts2[i]);
    
    int min = 2000000;
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            int diff = abs(alts1[i] - alts2[j]);
            if(diff < min) min = diff;
        }
    }
    printf("%d\n", min);
}

int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
    return 0;
}

