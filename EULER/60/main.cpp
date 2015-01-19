#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef struct Prime {
	int num;
	bool added;
} Prime;

vector<Prime> primes;

bool isPrime(int n)
{
	if(n % 2 == 0 || n == 1 || n == 0) return false;
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0) return false;
	return true;
}

bool canConcat(int a, int b)
{
	// a - b
	stringstream s1; s1 << a << b;
	int p1 = atoi(s1.str().c_str());
	if(!isPrime(p1)) return false;
	
	// b - a
	stringstream s2; s2 << b << a;
	int p2 = atoi(s2.str().c_str());
	if(!isPrime(p2)) return false;
	
	return true;
}

void rec(vector<Prime> cur)
{
	if(cur.size() == 5)
	{
		cout << "sum: " << cur[0].num + cur[1].num + cur[2].num + cur[3].num + cur[4].num << endl;
		for(vector<Prime>::iterator it = cur.begin(); it != cur.end(); it++) cout << it->num << " ";
		cout << endl;
		// exit(0);
	}
	
	// add primes
	for(vector<Prime>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		// check if it can be concatenated to every prime in the set already
		bool pos = true;
		for(vector<Prime>::iterator it2 = cur.begin(); it2 != cur.end(); it2++)
			if(!canConcat(it->num, it2->num)) pos = false;
			
		if(pos && !it->added)
		{
			it->added = true;
			cur.push_back(*it);
			rec(cur);
			cur.pop_back();
			it->added = false;
		}
	}
}

int main(int argc, char *argv[]) 
{
	for(int i = 2; i <= 10000; i++)
	{
		if(isPrime(i))
		{
			Prime p; p.num = i; p.added = false;
			primes.push_back(p);
		}
	}
	
	rec(vector<Prime>());
}