//
//  main.cpp
//  acpc10a
//
//  Created by M.A. de Vos on 22-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

void solve(int a, int b, int c)
{
    if(b - a == c - b) printf("AP %d\n", (c + b - a));
    else printf("GP %d\n", (c * (b / a)));
}

int main(int argc, const char * argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    while(a != 0 || b != 0 || c != 0)
    {
        solve(a, b, c);
        scanf("%d %d %d", &a, &b, &c);
    }
    
    return 0;
}

