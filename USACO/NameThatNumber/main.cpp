/*
 ID: mdmarti1
 PROG: namenum
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

char letters[8][3] = { { 'A', 'B', 'C' }, { 'D', 'E', 'F' }, { 'G', 'H', 'I' }, { 'J', 'K', 'L' }, { 'M', 'N', 'O' }, { 'P', 'R', 'S' }, { 'T', 'U', 'V' }, { 'W', 'X', 'Y' } };
size_t numletters;
string serial;
set<string> names;
bool pos;

ofstream fout;

string generateName(int num[])
{
    string name = "";
    for(int i = 0; i < numletters; i++)
    {
        int y = (int)(serial.at(i) - '0') - 2;
        int x = num[i];
        name += letters[y][x];
    }
    // cout << name << endl;
    return name;
}

void combinations(int current[], int n)
{
    if(n == numletters)
    {
        string name = generateName(current);
        if(names.find(name) != names.end())
        {
            pos = true;
            fout << name << endl;
        }
        return;
    }
    
    for(int i = 0; i < 3; i++)
    {
        current[n] = i;
        combinations(current, n+1);
    }
}

int main()
{
    fout.open("namenum.out");
    ifstream fin ("namenum.in");
    ifstream textin ("dict.txt");
    
    while(!textin.eof())
    {
        string name;
        textin >> name;
        names.insert(name);
    }
    fin >> serial;
    numletters = serial.length();
    
    int empty[12];
    combinations(empty, 0);
    
    if(!pos) fout << "NONE" << endl;
    
    return 0;
}