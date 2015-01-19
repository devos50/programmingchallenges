/*
 ID: mdmarti1
 PROG: gift1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    map<string, int> money;
    string names[10];
    
    int np;
    fin >> np;
    for(int i = 0; i < np; i++)
    {
        string name;
        fin >> name;
        names[i] = name;
        money[name] = 0;
    }
    
    // namen uitgelezen - lees uitgaves
    while(!fin.eof())
    {
        string giver;
        fin >> giver;
        int amount, n;
        fin >> amount >> n;
        if(n == 0) continue;
        int each = amount / n;
        for(int i = 0; i < n; i++)
        {
            string name;
            fin >> name;
            money[giver] -= each;
            money[name] += each;
        }
    }
    
    for(int i = 0; i < np; i++)
    {
        fout << names[i] << " " << money[names[i]] << endl;
        // cout << names[i] << " " << money[names[i]] << endl;
    }
    
    return 0;
}