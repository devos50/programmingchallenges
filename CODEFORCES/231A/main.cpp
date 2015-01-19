#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int ones = 0;
		for(int j = 0; j < 3; j++)
		{
			int k; cin >> k;
			if(k == 1) ones++;
		}
		if(ones >= 2) ans++;
	}
	cout << ans << endl;
}