/*
 ID: mdmarti1
 PROG: crypt1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool digits[11];

bool isValid(int num)
{
    while(num > 0)
    {
        int d = num % 10;
        if(!digits[d]) return false;
        num /= 10;
    }
    return true;
}

int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        int d;
        fin >> d;
        digits[d] = true;
    }
    
    int solutions = 0;
    for(int a = 1; a < 10; a++)
        for(int b = 1; b < 10; b++)
            for(int c = 1; c < 10; c++)
                for(int d = 1; d < 10; d++)
                    for(int e = 1; e < 10; e++)
                    {
                        if(!digits[a] || !digits[b] || !digits[c] || !digits[d] || !digits[e]) continue;
                        int num1 = a * 100 + b * 10 + c;
                        int num2 = d * 10 + e;
                        int product1 = e * num1;
                        if(product1 > 999 || !isValid(product1)) continue;
                        int product2 = d * num1;
                        if(product2 > 999 || !isValid(product2)) continue;
                        int res = num1 * num2;
                        if(res > 9999 || !isValid(res)) continue;
                        // cout << a << ", " << b << ", " << c << ", " << d << ", " << e << endl;
                        solutions++;
                    }
    fout << solutions << endl;
    cout << solutions << endl;
    
    return 0;
}