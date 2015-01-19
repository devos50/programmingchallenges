#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int c)
{
	int n1, n2, n3; cin >> n1 >> n2 >> n3;
	vector<int> vec; vec.push_back(n1); vec.push_back(n2); vec.push_back(n3);
	sort(vec.begin(), vec.end());
	cout << "Case " << c << ": " << vec[1] << endl;
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	for(int i = 0; i < n; i++) solve(i + 1);
}