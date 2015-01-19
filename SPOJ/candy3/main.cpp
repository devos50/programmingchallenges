//
//  main.cpp
//  candy3
//
//  Created by M.A. de Vos on 27-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>

void solve()
{
    long long int n;
    scanf("%lld", &n);
    long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        long long int c;
        scanf("%lld", &c);
        sum = (sum + c) % n;
    }
    
    if(sum % n == 0) printf("YES\n");
    else printf("NO\n");
}

int main(int argc, const char * argv[])
{
    long long int t;
    scanf("%lld", &t);
    while(t--) solve();
    
    return 0;
}

