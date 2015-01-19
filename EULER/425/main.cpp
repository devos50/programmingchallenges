#include <iostream>
#include <set>
#include <queue>
#include <sstream>
#include <map>

#define LINT 100000000

using namespace std;

set<int> primes;
map<int, set<int> > adj;
map<int, int> d;

int n = 1000;

// struct om de distances te vergelijken
struct compareDist
 {  
   bool operator()( int l, int r)  
   {  
       return d[l] > d[r];
   }  
 };

bool isPrime(int n)
{
	if(n == 2) return true;
	if(n % 2 == 0 || n == 1 || n == 0) return false;
	for(int i = 3; i * i <= n; i+= 2)
		if(n % i == 0) return false;
	return true;
}

void dijkstra(int start)
{
	// Node *v = get_node_with_id(3);
	for(set<int>::iterator it = primes.begin(); it != primes.end(); it++)
		d[*it] = LINT;
	
	set<int> settled;
	priority_queue<int, vector<int>, compareDist> unsettled;
	unsettled.push(start);
	d[start] = 2;
	
	while(!unsettled.empty())
	{
		int u = unsettled.top(); unsettled.pop();
		settled.insert(u);
		// cout << "u: " << u << endl;
		// relaxatie van de buren
		for(set<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = *it;
			
			if(settled.find(v) != settled.end()) continue;
			// cout << "d[u]: " << d[u] << ", d[v]: " << d[v] << endl; 
			if(d[v] > d[u])
			{
				// cout << "v: " << v << endl;
				if(d[u] < v) d[v] = v;
				else d[v] = d[u];
				// d[v] = d[u];
				unsettled.push(v);
			}
		}
	}
	
	// find all 2-relative primes
	set<int> twoprimes;
	for(set<int>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		// cout << *it << " => " << d[*it] << endl;
		if(d[*it] <= *it) twoprimes.insert(*it);
	}
	int ans = 0;
	for(set<int>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		if(twoprimes.find(*it) == twoprimes.end()) { ans += *it; cout << "prime: " << *it << endl; }
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	// find all primes to n
	for(int i = 0; i < n; i++)
		if(isPrime(i)) primes.insert(i);
	
	for(set<int>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		// change digits
		stringstream ss; ss << *it; string str = ss.str();
		for(int i = 0; i < str.size(); i++)
		{
			char oldchar = str.at(i);
			for(int j = '1' ;j <= '9'; j++)
			{
				if(j == oldchar) continue;
						
				str[i] = j;
				int newnum = atoi(str.c_str());
				
				if(newnum <= n && isPrime(newnum) && adj[*it].find(newnum) == adj[*it].end())
					adj[*it].insert(newnum);
					
			}
			str[i] = oldchar;
		}
		str = ss.str(); // restore
				
		// add digits to the left
		for(char i = '1'; i <= '9'; i++)
		{
			string newstr = i + str;
			int newnum = atoi(newstr.c_str());
			if(newnum <= n && isPrime(newnum) && adj[*it].find(newnum) == adj[*it].end())
				adj[*it].insert(newnum);
		}
	}
	
	// dijkstra
	dijkstra(2);
}