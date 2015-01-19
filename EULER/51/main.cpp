#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isprime(int num)
{
	if(num == 0 || num == 1) return false;
	if(num % 2 == 0) return false;
	for(int i = 3; i * i <= num; i+=2)
		if(num % i == 0) return false;
	return true;
}

void adjustDigits(vector<int> subset, int curnum)
{
	stringstream ss; ss << curnum;
	string strnum = ss.str();
	int primes = 0;
	
	bool containszero = false;
	for(int i = 0; i < subset.size(); i++) if(subset[i] == 0) containszero = true;
	vector<int> vprimes;
	
	for(int i = 0; i < 10; i++)
	{
		if(i == 0 && containszero) continue;
		for(int j = 0; j < subset.size(); j++)
		{
			strnum[subset[j]] = i + '0';
		}
		int newnum = atoi(strnum.c_str());
		if(isprime(newnum))
		{
			vprimes.push_back(newnum);
			primes++;
		}
	}
	/*
	if(primes == 7)
	{
		cout << "cur num: " << curnum << endl;
	}
	*/
	if(primes == 8)
	{
		cout << "found solution!" << endl;
		cout << "primes: " << endl;
		for(int i = 0; i < vprimes.size(); i++) cout << vprimes[i] << " ";
		cout << endl;
		
		cout << "string: " << ss.str() << endl;
		cout << "subset: ";
		for(int i = 0; i < subset.size(); i++) cout << subset[i] << " ";
		exit(0);
	}
}

void makeCombinations(vector<int> nums, int curnum)
{	
	int n = nums.size();
	for(long i = 0; i < (1 << n); i++)
	{
		vector<int> subset;
		for(int j = 0; j < n; j++)
		{
			if(((i >> j) & 1) == 1) subset.push_back(nums[j]);
		}
		
		if(subset.size() > 0) adjustDigits(subset, curnum);
	}
}

int main(int argc, char *argv[]) 
{
	int cur = 1; 
	
	while(true)
	{
		if(!isprime(cur)) {cur++; continue; }
		int curcopy = cur;
		int digits = 0; while (curcopy != 0) { curcopy /= 10; digits++; }
		vector<int> nums;
		for(int i = 0; i < digits; i++) nums.push_back(i);
		makeCombinations(nums, cur);
		cur++;
	}
}