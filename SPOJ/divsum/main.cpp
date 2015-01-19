//
//  main.cpp
//  divsum
//
//  Created by M.A. de Vos on 21-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>

using namespace std;

void solve()
{
    int res = 1;
    int num = 0;
    scanf("%d", &num);
    
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0)
        {
            res += i;
            if(i != (num / i)) res += (num / i);
        }
    }
    
    if(num == 1) printf("0\n");
    else printf("%d\n", res);
}

int main(int argc, const char * argv[])
{
    int t;
    cin >> t;
    
    while(t--) solve();
    
    return 0;
}

