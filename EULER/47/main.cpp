#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> primeFactors(int num)
{
	// find prime factors
	vector<int> primeFactors;
	int n = num;
	for(int i = 2; i <= n; i++)
	{
		while(n % i == 0) { primeFactors.push_back(i); n /= i; }
	}
	
	set<int> distinctFactors;
	int i = 0;
	while(i != primeFactors.size())
	{
		int curval = primeFactors[i];
		int endres = curval; i++;
		while(primeFactors[i] == curval && i != primeFactors.size()) { endres *= curval; i++; }
		distinctFactors.insert(endres);	
	}
	return distinctFactors;
}

int main(int argc, char *argv[]) 
{
	int cur = 210;
	while(true)
	{
		if(cur % 1000 == 0) cout << "cur: " << cur << endl;
		
		set<int> s1 = primeFactors(cur);
		set<int> s2 = primeFactors(cur+1);
		set<int> s3 = primeFactors(cur+2);
		set<int> s4 = primeFactors(cur+3);
		
		if(s1.size() == 4 && s2.size() == 4 && s3.size() == 4 && s4.size() == 4)
		{
			set<int> allprimes;
			for(set<int>::iterator it = s1.begin(); it != s1.end(); it++) allprimes.insert(*it);
			for(set<int>::iterator it = s2.begin(); it != s2.end(); it++) allprimes.insert(*it);
			for(set<int>::iterator it = s3.begin(); it != s3.end(); it++) allprimes.insert(*it);
			for(set<int>::iterator it = s4.begin(); it != s4.end(); it++) allprimes.insert(*it);
			if(allprimes.size() == 16)
			{
				cout << "found solution: " << cur;
				return 0;
			}
		}
		
		cur++;
	}
}