#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

set<string> sets;

void print_vec(vector<int> v)
{
	cout << "vector: ";
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool is_prime(int n)
{
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	if(n == 0 || n == 1) return false;
	
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0) return false;
	return true;
}

void rec(vector<int> cur)
{
	// print_vec(cur);
	
	// get the used digits
	bool used[11]; for(int i = 1; i < 10; i++) used[i] = false;
	int used_count = 0;
	for(vector<int>::iterator it = cur.begin(); it != cur.end(); it++)
	{
		int num = *it;
		while(num != 0)
		{
			int dig = num % 10; num /= 10;
			used[dig] = true;
			used_count++;
		}
	}
	
	if(used_count == 9 && is_prime(cur.back()))
	{
		vector<int> cpy = cur;
		sort(cpy.begin(), cpy.end());
		stringstream ss;
		for(vector<int>::iterator it = cpy.begin(); it != cpy.end(); it++) ss << *it << ",";
		sets.insert(ss.str());
	}
	
	// if cur is empty
	if(cur.size() == 0)
	{
		for(int i = 1; i < 10; i++)
		{
			cur.push_back(i);
			rec(cur);
			cur.pop_back();
		}
	}
	else
	{
		// first put a character after the last element of the vector
		int orig = cur.back();
		for(int i = 1; i < 10; i++)
		{
			if(used[i]) continue;
			int num = orig;
			num *= 10; num += i;
			cur.pop_back();
			cur.push_back(num);
			rec(cur);
			cur.pop_back();
			cur.push_back(orig);
		}
		
		// if the last element of the vector is prime, insert a new element
		if(is_prime(orig))
		{
			for(int i = 1; i < 10; i++)
			{
				if(used[i]) continue;
				cur.push_back(i);
				rec(cur);
				cur.pop_back();
			}
		}
	}
}

int main(int argc, char *argv[]) 
{
	vector<int> v;
	rec(v);
	cout << sets.size();
}