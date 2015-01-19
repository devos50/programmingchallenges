/*
 ID: mdmarti1
 PROG: friday
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int monthlengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isCenturyYear(int year)
{
    return (year == 1900 || year == 2100 || year == 2200 || year == 2300);
}

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;
    
    int dayindex = 0; // 0 = maandag, 1 = dinsdag ... 6 = zondag
    int freq[8];
    for(int i = 0; i < 8; i++) freq[i] = 0;
    
    for(int year = 1900; year <= 1900 + n - 1; year++)
    {
        for(int month = 1; month <= 12; month++)
        {
            int numdays = monthlengths[month - 1];
            if(month == 2 && year % 4 == 0) numdays = 29;
            if(month == 2 && isCenturyYear(year)) numdays = 28;
            
            for(int day = 1; day <= numdays; day++)
            {
                if(day == 13)
                    freq[dayindex]++;
                
                dayindex++;
                dayindex %= 7;
            }
        }
    }
    fout << freq[5] << " " << freq[6] << " " << freq[0] << " " << freq[1] << " " << freq[2] << " " << freq[3] << " " << freq[4] << endl;
    
    return 0;
}