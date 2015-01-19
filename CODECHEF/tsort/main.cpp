#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	int t; scanf("%d", &t);
	vector<int> vec;
	for(int i = 0; i < t; i++)
	{
		int v; scanf("%d", &v);
		vec.push_back(v);
	}
	sort(vec.begin(), vec.end());
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		printf("%d\n", *it);
}