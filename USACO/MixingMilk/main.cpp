/*
 ID: mdmarti1
 PROG: milk
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int getMinPrice(map<int, int> amounts)
{
    int min = 10000;
    for(map<int, int>::iterator it = amounts.begin(); it != amounts.end(); it++)
    {
        int key = it->first;
        if(key < min) min = key;
    }
    return min;
}

int main() // ans 993159
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n, m;
    fin >> n >> m;
    
    if(m == 0)
    {
        fout << "0" << endl;
        return 0;
    }
    
    map<int, int> amounts;
    
    for(int i = 0; i < m; i++)
    {
        int price, amount;
        fin >> price >> amount;
        if(amounts[price]) amounts[price] += amount;
        else amounts[price] = amount;
    }
    
    int totalPrice = 0;
    while(n > 0)
    {
        int min = getMinPrice(amounts);
        int amount = amounts[min];
        if(amount <= n)
        {
            n -= amount;
            totalPrice += amount * min;
            cout << "adding " << amount * min << ", left" << n << endl;
            amounts.erase(min);
        }
        else
        {
            totalPrice += n * min;
            n = 0;
        }
    }
    fout << totalPrice << endl;
    
    return 0;
}