/*
 ID: mdmarti1
 PROG: transform
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char orig[11][11];
char trans[11][11];
int n;

bool check1()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(orig[i][j] != trans[n - j - 1][i]) return false;
    return true;
}

bool check2()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(orig[i][j] != trans[n - i - 1][n - j - 1]) return false;
    return true;
}

bool check3()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(orig[i][j] != trans[j][n - i - 1]) return false;
    return true;
}

bool check4()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(orig[i][j] != trans[i][n - j - 1]) return false;
    return true;
}

bool check5()
{
    // make a copy of orig
    int cpy[n][n];
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            cpy[y][x] = orig[y][x];
    
    // mirror orig
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            orig[i][j] = cpy[i][n - j - 1];
    
    bool can = false;
    if(check1() || check2() || check3())
    {
        can = true;
    }
    
    // restore orig
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            orig[y][x] = cpy[y][x];
    
    return can;
}

bool check6()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(orig[i][j] == trans[i][j]) return false;
    return true;
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin >> n;
    
    for(int i = 0; i < n; i++)
    {
        string s;
        fin >> s;
        for(int j = 0; j < n; j++) orig[i][j] = s.at(j);
    }
    
    cout << "N: " << n << endl;
    
    for(int i = 0; i < n; i++)
    {
        string s;
        fin >> s;
        for(int j = 0; j < n; j++) trans[i][j] = s.at(j);
    }
    
    if(check1()) fout << "1" << endl;
    else if(check2()) fout << "2" << endl;
    else if(check3()) fout << "3" << endl;
    else if(check4()) fout << "4" << endl;
    else if(check5()) fout << "5" << endl;
    else if(check6()) fout << "6" << endl;
    else fout << "7" << endl;
    
    return 0;
}