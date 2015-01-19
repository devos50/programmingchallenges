//
//  main.cpp
//  vowels
//
//  Created by M.A. de Vos on 20-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    string str;
    int vowels = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'O' || str[i] == 'o' || str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'u' || str[i] == 'U') vowels++;
    }
    printf("%d", vowels);
    
    return 0;
}

