/*
 ID: mdmarti1
 PROG: palsquare
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    
    int n;
    fin >> n;
    
    for(int i = 1; i <= 300; i++)
    {
        int sq = i*i;
        if(isPalindrome(changeBase(sq, n))) fout << changeBase(i, n) << " " << changeBase(sq, n) << endl;
    }
    
    return 0;
}