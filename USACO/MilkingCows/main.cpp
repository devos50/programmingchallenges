/*
 ID: mdmarti1
 PROG: milk2
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    bool milking[1000005];
    
    int n;
    fin >> n;
    int min = 2000000, max = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a;
        fin >> b;
        if(a < min) min = a;
        if(b > max) max = b;
        for(int j = a+1; j <= b; j++) milking[j] = true;
    }
    
    // get longest/shortest
    int maxyes = 0, maxno = 0;
    int curyes = 0, curno = 0;
    for(int i = min+1; i <= max+1; i++)
    {
        if(milking[i])
        {
            curyes++;
            if(curno > maxno) maxno = curno;
            // if(curyes > maxno && i == max) maxyes = curyes;
            curno = 0;
        }
        else
        {
            curno++;
            if(curyes > maxyes || i == max) maxyes = curyes;
            // if(curno > maxno && i == max) maxno = curno;
            curyes = 0;
        }
    }
    fout << maxyes << " " << maxno << endl;
    cout << maxyes << " " << maxno << endl;
    
    return 0;
}