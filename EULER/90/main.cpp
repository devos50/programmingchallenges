#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > combinations;
string pairs[9] = { "01", "04", "09", "16", "25", "36", "49", "64", "81" };

bool contains(vector<int> vec, int a)
{
	return find(vec.begin(), vec.end(), a) != vec.end();
}

bool can_make(vector<int> a, vector<int> b, string num)
{
	int n1 = num[0] - '0';
	int n2 = num[1] - '0';
	
	if((contains(a, n1) && contains(b, n2)) || (contains(a, n2) && contains(b, n1))) return true;
	if(n1 == 9) 
	{
		n1 = 6;
		if((contains(a, n1) && contains(b, n2)) || (contains(a, n2) && contains(b, n1))) return true;
		n1 = 9;
	}
	if(n1 == 6)
	{
		n1 = 9;
		if((contains(a, n1) && contains(b, n2)) || (contains(a, n2) && contains(b, n1))) return true;
		n1 = 9;
	}
	if(n2 == 9) 
	{
		n2 = 6;
		if((contains(a, n1) && contains(b, n2)) || (contains(a, n2) && contains(b, n1))) return true;
		n2 = 9;
	}
	if(n2 == 6) 
	{
		n2 = 9;
		if((contains(a, n1) && contains(b, n2)) || (contains(a, n2) && contains(b, n1))) return true;
		n2 = 6;
	}
	
	return false;
}

bool is_valid(vector<int> a, vector<int> b)
{
	for(int i = 0; i < 9; i++)
	{
		if(!can_make(a, b, pairs[i])) return false;
	}
	
	return true;
}

void combs(int N, int K)
{
	string bitmask(K, 1);
	bitmask.resize(N, 0);
	
	do
	{
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			if(bitmask[i]) vec.push_back(i);
		}
		combinations.push_back(vec);
	} while(prev_permutation(bitmask.begin(), bitmask.end()));
}

int main(int argc, char *argv[]) 
{
	combs(10, 6);
	
	int ans = 0;
	for(vector<vector<int> >::iterator it1 = combinations.begin(); it1 != combinations.end(); it1++)
	{
		for(vector<vector<int> >::iterator it2 = combinations.begin(); it2 != combinations.end(); it2++)
		{
			if(is_valid(*it1, *it2)) ans++;
		}
	}
	cout << ans / 2;
}