/*
 ID: mdmarti1
 PROG: beads
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    
    int beads;
    fin >> beads;
    string s;
    fin >> s;
    s = s + s + s;
    cout << s << endl;
    
    // everything b/w?
    bool posb = true, posr = true;
    for(int i = 0; i < s.length(); i++)
        if(s.at(i) == 'r')
            posb = false;
    for(int i = 0; i < s.length(); i++)
        if(s.at(i) == 'b')
           posr = false;
    if(posb || posr)
    {
        fout << beads << endl;
        return 0;
    }
    
    // brute force
    int max = -1;
    for(int i = beads-1; i < 2*beads; i++)
    {
        int maxl = 1, maxr = 1;
        
        char left = s.at(i); char right = s.at(i+1);
        int index = i-1;
        
        // left
        if(left == 'w')
        {
            int maxl1 = 1, maxl2 = 1;
            left = 'b';
            while(index >= 0 && (s.at(index) == 'w' || s.at(index) == left)) // left met b
            {
                maxl1++;
                index--;
            }
            
            index = i - 1;
            left = 'r';
            while(index >= 0 && (s.at(index) == 'w' || s.at(index) == left)) // left met b
            {
                maxl2++;
                index--;
            }
            maxl = (maxl1 > maxl2) ? maxl1 : maxl2;
        }
        else
        {
            index = i-1;
            while(index >= 0 && (s.at(index) == 'w' || s.at(index) == left)) // left met b
            {
                maxl++;
                index--;
            }
        }
        
        // right
        if(right == 'w')
        {
            index = i + 2;
            int maxr1 = 1, maxr2 = 1;
            right = 'b';
            while(index <= s.length() - 1 && (s.at(index) == 'w' || s.at(index) == right)) // right
            {
                maxr1++;
                index++;
            }
            
            index = i + 2;
            right = 'r';
            while(index <= s.length() - 1 && (s.at(index) == 'w' || s.at(index) == right)) // right
            {
                maxr2++;
                index++;
            }
            // cout << "maxr1: " << maxr1 << ", maxr2: " << maxr2 << endl;
            maxr = (maxr1 > maxr2) ? maxr1 : maxr2;
        }
        else
        {
            index = i+2;
            while(index <= s.length() - 1 && (s.at(index) == 'w' || s.at(index) == right)) // right
            {
                maxr++;
                index++;
            }
        }
        cout << "i: " << i << " left: " << left << ", right: " << right << ", maxl: " << maxl << ", maxr: " << maxr << endl;
        
        if(maxl + maxr > max) max = maxl + maxr;
    }
    
    if(max > beads) max = beads;
    fout << max << endl;
    
    return 0;
}