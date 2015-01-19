//
//  main.cpp
//  favdice
//
//  Created by M.A. de Vos on 19-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>

using namespace std;

void solve()
{
    int num;
    scanf("%d", &num);
    
    double res = 0;
    
    for(int i = num; i > 0; i--)
    {
        res += ((double)num / (double)i);
    }
    
    printf("%.2f\n", res);
}

int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}

