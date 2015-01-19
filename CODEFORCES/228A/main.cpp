#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) 
{
	set<int> s;
	for(int i = 0; i < 4; i++)
	{
		int n; cin >> n;
		s.insert(n);
	}
	cout << 4 - s.size() << endl;
}