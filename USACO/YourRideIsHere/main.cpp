/*
 ID: mdmarti1
 PROG: ride
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    string group, comet;
    fin >> group >> comet;
    
    int res1 = 1, res2 = 1;
    for(int i = 0; i < group.length(); i++)
    {
        char c = group.at(i);
        res1 *= ((int)c - 'A' + 1);
    }
    res1 %= 47;
    
    for(int i = 0; i < comet.length(); i++)
    {
        char c = comet.at(i);
        res2 *= ((int)c - 'A' + 1);
    }
    
    res2 %= 47;
    
    if(res1 == res2) fout << "GO" << endl;
    else fout << "STAY" << endl;
    
    return 0;
}