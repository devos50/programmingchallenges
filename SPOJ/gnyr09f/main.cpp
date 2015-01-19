//
//  main.cpp
//  gnyr09f
//
//  Created by M.A. de Vos on 01-12-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>

int dp[101][101];

void calcArray()
{
    dp[0][0] = 1;
    dp[1][0] = 2;
    
    // vul eerste kolom
    for(int i = 2; i <= 100; i++) dp[i][0] = dp[i-1][0] + dp[i-2][0];
    
    // vul de rest van de tabel
    for(int x = 1; x <= 100; x++)
    {
        for(int y = 2; y <= 100; y++)
        {
            dp[y][x] = dp[y-1][x] + dp[y-1][x-1] + dp[y-2][x] - dp[y-2][x-1];
        }
    }
}

void solve()
{
    int c = 0, n = 0, k = 0;
    scanf("%d %d %d", &c, &n, &k);
    printf("%d %d\n", c, dp[n][k]);
}

int main(int argc, const char * argv[])
{
    int t = 0;
    scanf("%d", &t);
    calcArray();
    
    while(t--) solve();
    
    return 0;
}

