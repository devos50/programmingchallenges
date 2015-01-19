//
//  main.cpp
//  fashion
//
//  Created by M.A. de Vos on 21-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int m;
    scanf("%d", &m);
    int ratesM[m], ratesF[m];
    for(int i = 0; i < m; i++) { int n; scanf("%d", &n); ratesM[i] = n; }
    for(int i = 0; i < m; i++) { int n; scanf("%d", &n); ratesF[i] = n; }
    
    sort(ratesM, ratesM + m);
    sort(ratesF, ratesF + m);
    
    int res = 0;
    for(int i = 0; i < m; i++) res += ratesM[i] * ratesF[i];
    printf("%d\n", res);
}

int main(int argc, const char * argv[])
{

    // insert code here...
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
    return 0;
}

