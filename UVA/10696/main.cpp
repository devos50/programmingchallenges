//
//  main.cpp
//  10696
//
//  Created by Martijn de Vos on 09-12-12.
//  Copyright (c) 2012 Martijn de Vos. All rights reserved.
//

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[])
{
    int n = 0;
    scanf("%d", &n);
    while(n != 0)
    {
        int res = (n > 100) ? n - 10 : 91;
        printf("f91(%d) = %d\n", n, res);
        scanf("%d", &n);
    }
    return 0;
}

