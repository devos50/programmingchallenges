/*
 ID: mdmarti1
 PROG: pprime
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

int palins = 0;
int a, b;
vector<int> results;

bool isPrime(int num)
{
	if(num == 0 || num == 1) return false;
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}

void genPalins(string s)
{
	string pal1 = string(s.rbegin(), s.rend()) + s;
	string pal2 = string(s.rbegin(), s.rend() - 1) + s;
	palins += 2;
	
	int num1 = atoi(pal1.c_str());
	int num2 = atoi(pal2.c_str());
	// cout << "num1: " << num1 << ", num2: " << num2 << endl;
	
	if(num1 <= b && num1 >= a && isPrime(num1) && num1 % 10 != 0) results.push_back(num1);
	if(num2 <= b && num2 >= a && isPrime(num2) && num2 % 10 != 0) results.push_back(num2);
}

int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");

    fin >> a >> b;
	
	// generate prime num
	for(int n1 = 0; n1 < 10; n1++)
	{
		string s = string(); s.push_back(n1 + '0');
		genPalins(s);
		
		for(int n2 = 0; n2 < 10; n2++)
		{
			s.push_back(n2 + '0');
			genPalins(s);
			
			for(int n3 = 0; n3 < 10; n3++)
			{
				s.push_back(n3 + '0');
				genPalins(s);
				
				for(int n4 = 0; n4 < 10; n4++)
				{
					s.push_back(n4 + '0');
					genPalins(s);
					s = s.substr(0, s.size() - 1);
				}
				s = s.substr(0, s.size() - 1);
			}
			s = s.substr(0, s.size() - 1);
		}
		s = s.substr(0, s.size() - 1);
	}
	
	// cout << "palins: " << palins << endl;
	// cout << "results: " << results.size() << endl;
	// cout << "last in results: " << results[results.size() - 1] << endl;
	
	sort(results.begin(), results.end());
	for(vector<int>::iterator it = results.begin(); it != results.end(); it++) fout << *it << endl;
	
    return 0;
}