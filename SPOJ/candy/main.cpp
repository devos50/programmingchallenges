//
//  main.cpp
//  candy
//
//  Created by M.A. de Vos on 21-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

void solve(int num)
{
    int bags[num];
    int totalCandies = 0;
    for(int i = 0; i < num; i++)
    {
        int cand;
        scanf("%d", &cand);
        bags[i] = cand;
        totalCandies += cand;
    }
    
    // printf("%d %d", totalCandies, num);
    
    if(totalCandies % num != 0) printf("-1\n");
    else
    {
        int perbag = totalCandies / num;
        int swaps = 0;
        for(int i = 0; i < num; i++) swaps += (abs(bags[i] - perbag));
        printf("%d\n", swaps / 2);
    }
}

int main(int argc, const char * argv[])
{
    int num;
    scanf("%d", &num);
    while(num != -1)
    {
        solve(num);
        scanf("%d", &num);
    }
    
    return 0;
}

