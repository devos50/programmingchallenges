//
//  main.cpp
//  palin
//
//  Created by M.A. de Vos on 22-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int compare(string b1, string b2)
{
    int length = (int)b1.length();
    for(int i = 0; i < length; i++)
    {
        if((int)b1[i] < (int)b2[i]) return -1;
        if((int)b1[i] > (int)b2[i]) return 1;
    }
    return 0;
}

void solve()
{
    string s;
    cin >> s;
    
    int index = (int)s.length() - 1;
    bool shouldStop = false;
    // tel 1 op
    while(index != -1 && !shouldStop)
    {
        if(s[index] == '9')
        {
            s[index] = '0';
            index--;
        }
        else
        {
            s[index] = s[index] + 1;
            shouldStop = true;
        }
    }
    
    if(index == -1) s = "1" + s;
    
    string nstr;
    if(s.length() % 2 == 0)
    {
        int mid = s.length() / 2 - 1;
        string t = s.substr(0, mid + 1);
        reverse(t.begin(), t.end());
        nstr = s.substr(0, mid + 1) + t;
        
        if(compare(nstr, s) < 0)
        {
            bool stop = false;
            int i = mid;
            if(nstr[i] == '9')
            {
                while(!stop)
                {
                    if(nstr[i] == '9')
                    {
                        nstr[i] = '0';
                        nstr[nstr.length() - i - 1] = '0';
                    }
                    else
                    {
                        nstr[i] = nstr[i] + 1;
                        nstr[nstr.length() - i - 1] = nstr[nstr.length() - i - 1] + 1;
                        stop = true;
                    }
                    i--;
                }
            }
            else
            {
                nstr[mid] = nstr[mid] + 1;
                nstr[mid+1] = nstr[mid+1] + 1;
            }
        }
        printf("%s\n", nstr.c_str());
    }
    else
    {
        int mid = (int)s.length() / 2;
        string t = s.substr(0, mid);
        reverse(t.begin(), t.end());
        nstr = s.substr(0, mid + 1) + t;
        
        if(compare(nstr, s) < 0)
        {
            if(nstr[mid] == '9')
            {
                int i = mid;
                nstr[mid] = '0';
                bool stop = false; i--;
                while(!stop)
                {
                    if(nstr[i] == '9')
                    {
                        nstr[i] = '0';
                        nstr[nstr.length() - 1 - i] = '0';
                    }
                    else
                    {
                        nstr[i] = nstr[i] + 1;
                        nstr[nstr.length() - 1 - i] = nstr[nstr.length() - 1 - i] + 1;
                        stop = true;
                    }
                    i--;
                }
            }
            else
            {
                nstr[mid] = nstr[mid] + 1;
            }
        }
        printf("%s\n", nstr.c_str());
    }
}

int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
    return 0;
}

