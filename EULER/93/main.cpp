#include <iostream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

set<double> nums;

void rec(vector<double> l);

vector<double> change_elements(vector<double> vec, int ind1, int ind2, int op)
{
	double a = vec[ind1];
	double b = vec[ind2];
	double res = -1;
	if(op == 0) res = a + b;
	else if(op == 1) res = a - b;
	else if(op == 2) res = a * b;
	else if(op == 3 && b != 0) res = a / b;
	
	if(res == 24) cout << "a: " << a << ", b: " << b << ", op: " << op << endl;
	
	if(res < 0) return vec;
	
	vector<double>::iterator it = vec.begin() + ind1;
	
	vec.insert(vec.begin() + ind1, res);
	vec.erase(vec.begin() + ind1 + 1, vec.begin() + ind1 + 3);
	
	// for(vector<int>::iterator it2 = vec.begin(); it2 != vec.end(); it2++) cout << *it2 << " ";
	// cout << endl;
	rec(vec);
	
	return vec;
}

void rec(vector<double> l)
{
	if(l.size() == 1)
	{
		if(l[0] == (int)l[0] && l[0] != 0) { nums.insert(l[0]); }
		return;
	}
	
	// choose two indices every time and recurse down
	for(int i = 0; i < l.size() - 1; i++)
	{
		for(int j = 0; j < 4; j++) change_elements(l, i, i+1, j);
	}
}

int main(int argc, char *argv[]) 
{
	int ans = -1;
	
	// for(double a = 0; a <= 9; a++)
	//	for(double b = a + 1; b <= 9; b++)
	//		for(double c = b + 1; c <= 9; c++)
	//			for(double d = c + 1; d <= 9; d++)
				{
					int a = 3, b = 3, c = 8, d = 8;
					nums.clear();
					
					vector<double> l;
					l.push_back(a);
					l.push_back(b);
					l.push_back(c);
					l.push_back(d);
						
					do {
						rec(l);
					} while(next_permutation(l.begin(), l.end()));
					
					double count = 1, prev = *nums.begin() - 1;
					for(set<double>::iterator it = nums.begin(); it != nums.end(); it++)
					{
						cout << "num: " << *it << " ";
						//if(*it == prev + 1) count++;
						//else break;
						prev = *it;
					}
					
					// cout << "pos: " << nums.size() << endl;
					
					if(count > ans) 
					{
						stringstream ss; ss << a << b << c << d;
						cout << ss.str() << ", size: " << count << endl;
						ans = count;
					}
				}
	
	// cout << ans << endl;
	// cout << nums.size() << endl;
}