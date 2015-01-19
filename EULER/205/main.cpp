#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

vector<int> a_nums;
vector<int> b_nums;
set<int> a_set;
set<int> b_set;

double p_a(int n)
{
	int t = 0;
	for(vector<int>::iterator it = a_nums.begin(); it != a_nums.end(); it++)
		if(*it == n) t++;
	return (double)t / (double)a_nums.size();
}

double p_b(int n)
{
	int t = 0;
	for(vector<int>::iterator it = b_nums.begin(); it != b_nums.end(); it++)
		if(*it == n) t++;
	return (double)t / (double)b_nums.size();
}

int main(int argc, char *argv[]) 
{
	// numbers of A
	for(int a = 1; a <= 4; a++)
		for(int b = 1; b <= 4; b++)
			for(int c = 1; c <= 4; c++)
				for(int d = 1; d <= 4; d++)
					for(int e = 1; e <= 4; e++)
						for(int f = 1; f <= 4; f++)
							for(int g = 1; g <= 4; g++)
								for(int h = 1; h <= 4; h++)
									for(int i = 1; i <= 4; i++)
				{
					// cout << a << " " << b << " " << c << " " << d << endl;
					a_nums.push_back(a + b + c + d + e + f + g + h + i);
					a_set.insert(a + b + c + d + e + f + g + h + i);
				}
				
	// numbers of B
	for(int a = 1; a <= 6; a++)
		for(int b = 1; b <= 6; b++)
			for(int c = 1; c <= 6; c++)
				for(int d = 1; d <= 6; d++)
					for(int e = 1; e <= 6; e++)
						for(int f = 1; f <= 6; f++)
						{
							b_nums.push_back(a + b + c + d + e + f);
							b_set.insert(a + b + c + d + e + f);
						}
	
	double ans = 0.0;
	for(set<int>::iterator it = a_set.begin(); it != a_set.end(); it++)
	{
		for(set<int>::iterator it2 = b_set.begin(); it2 != b_set.end(); it2++)
		{
			if(*it > *it2)
			{
				double pa = p_a(*it);
				double pb = p_b(*it2);
				ans += pa * pb;
			}
		}
	}
	printf("%.9f", ans);
}