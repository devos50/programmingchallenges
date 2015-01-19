/*
 ID: mdmarti1
 PROG: barn1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    
    vector<vector<int> > sets;
    vector<int> init;
    int m, s, c;
    
    fin >> m >> s >> c;
    
    if(m > c)
    {
        fout << c << endl;
        return 0;
    }
    
    for(int i = 0; i < c; i++)
    {
        int stall;
        fin >> stall;
        init.push_back(stall);
    }
    
    sort(init.begin(), init.end());
    sets.push_back(init);
    
    for(int i = 1; i < m; i++)
    {
        // iterate over every set and find the one with the largest difference
        
        int max = -1, vindex = -1, index = -1;
        for(int j = 0; j < sets.size(); j++)
        {
            vector<int> v = sets.at(j);
            for(int k = 0; k < v.size() - 1; k++)
                if(v.at(k+1) - v.at(k) > max)
                {
                    max = v.at(k+1) - v.at(k);
                    vindex = j;
                    index = k;
                }
        }
        
        // split the vector
        vector<int> v = sets.at(vindex);
        vector<int> new1, new2;
        for(int i = 0; i <= index; i++) new1.push_back(v.at(i));
        for(int i = index+1; i < v.size(); i++) new2.push_back(v.at(i));
        sets.erase(sets.begin() + vindex);
        sets.push_back(new1); sets.push_back(new2);
        
        cout << "max: " << max << endl;
    }
    
    // calculate result
    int res = 0;
    for(int i = 0; i < sets.size(); i++)
    {
        vector<int> v = sets.at(i);
        res += (v.at(v.size() - 1) - v.at(0) + 1);
    }
    cout << "sets: " << sets.size() << endl;
    
    fout << res << endl;
    
    return 0;
}