/*
 ID: mdmarti1
 PROG: dualpal
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int n, s;

bool isPalindrome(string s)
{
    for(int i = 0; i < s.length() / 2; i++)
    {
        if(s.at(i) != s.at(s.length() - i - 1)) return false;
    }
    return true;
}

string changeBase(int sq, int b)
{
    string res;
    while(sq > 0)
    {
        stringstream s;
        char c;
        int mod = sq % b;
        if(mod <= 9) c = (char)(mod + '0');
        else c = (char)((mod - 10) + 'A');
        s << c << res;
        res = s.str();
        sq /= b;
    }
    return res;
}

int main()
{
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    fin >> n >> s;
    
    int c = 0;
    int cur = s + 1;
    while(c != n)
    {
        // loop over each base
        int counter = 0;
        for(int j = 2; j <= 10; j++)
        {
            if(isPalindrome(changeBase(cur, j))) counter++;
        }
        if(counter >= 2) { fout << cur << endl; c++; }
        cur++;
    }
    
    return 0;
}