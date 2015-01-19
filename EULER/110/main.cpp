#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	set<long long> nums;
	set<long long> newset;
	nums.insert(3); nums.insert(5); nums.insert(7);
	
	newset = nums;
	
	for(long long i = 0; i < 20; i++)
	{
		set<long long> toinsert;
		
		// multiply every number in newset with every number in the old set
		for(set<long long>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			for(set<long long>::iterator it2 = newset.begin(); it2 != newset.end(); it2++)
			{
				long long newnum = *it * *it2;
				if(newnum < 16000000) toinsert.insert(*it * *it2);
			}
		}
		for(set<long long>::iterator it = toinsert.begin(); it != toinsert.end(); it++)
		{
			newset.insert(*it);
		}
	}
	
	for(set<long long>::iterator it = newset.begin(); it != newset.end(); it++)
	{
		if(*it > 8000000) 
		{
			int n = *it;
			vector<long long> divs;
			while(n != 1)
			{
				for(set<long long>::iterator it2 = nums.begin(); it2 != nums.end(); it2++)
				{
					if(n % *it2 == 0) { cout << "dividing by " << *it2 << ", n: " << n << endl; n /= *it2; divs.push_back(*it2); break; }
				}
			}
			cout << "closest: " << *it << ", divs: " << divs.size() << endl; break; 
		}
	}
}