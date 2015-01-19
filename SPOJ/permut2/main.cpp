//
//  main.cpp
//  permut2
//
//  Created by M.A. de Vos on 01-12-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

void solve(int t)
{
    map<unsigned int, unsigned int> m;
    for(int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        m[i] = n;
    }
    
    // check inverse
    for(map<unsigned int, unsigned int>::iterator itr = m.begin(); itr != m.end(); itr++)
    {
        int key = (*itr).first;
        int val = (*itr).second;
        if(m[val] != key)
        {
            printf("not ambiguous\n");
            return;
        }
    }
    printf("ambiguous\n");
}

int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    while(t != 0)
    {
        solve(t);
        scanf("%d", &t);
    }
    
    return 0;
}

