#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cstdlib>
#include <set>

using namespace std;

vector<string> perms;

void genPermutations(string prefix, string str)
{
	int n = str.size();
	if(n == 0) perms.push_back(prefix);
	else
	{
		for(int i = 0; i < n; i++)
		{
			string newchar = ""; newchar.push_back(str.at(i));
			genPermutations(prefix + newchar, str.substr(0, i) + str.substr(i+1, n));
		}
	}
}

bool isPrime(int num)
{
	if(num == 0 || num == 2) return false;
	for(int i = 3; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}

void processSubset(vector<string> subset)
{
	int num1 = atoi(subset[0].c_str());
	int num2 = atoi(subset[1].c_str());
	int num3 = atoi(subset[2].c_str());
	
	// check if they are distinct
	set<int> nums; nums.insert(num1); nums.insert(num2); nums.insert(num3);
	if(nums.size() < 3) return;
	
	if(!isPrime(num1) || !isPrime(num2) || !isPrime(num3)) return;
	
	if(abs(num1 - num2) == abs(num2 - num3) && abs(num1 - num2) != 0)
	{
		cout << "found nums: " << num1 << ", " << num2 << ", " << num3 << endl;
	}
}

void subset(vector<string> arr, int size, int left, int index, vector<string> &l)
{
	if(left == 0)
	{
		processSubset(l);
		
		return;
	}
	for(int i = index; i < size; i++)
	{
		l.push_back(arr[i]);
		subset(arr, size, left - 1, i+1, l);
		l.pop_back();
	}
}

int main(int argc, char *argv[]) 
{
	for(int i = 1000; i < 10000; i++)
	{
		stringstream s; s << i;
		if(i % 100 == 0) cout << "i: " << i << endl;
		perms.clear();
		genPermutations("",s.str());
			
		vector<string> lt;
		subset(perms, 24, 3, 0, lt);
	}
}