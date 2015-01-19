#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, m; cin >> n >> m;
	int i = 1;
	while(true)
	{
		if(i > n) i = 1;
		if(i > m) break;
		m -= i;
		i++;
	}
	cout << m << endl;
}