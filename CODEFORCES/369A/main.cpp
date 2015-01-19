#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, m, k, type; cin >> n >> m >> k;
	int ans = 0;
	for(int i = 0; i < n; i++)
		{
			cin >> type;
			
			if (type == 1)
			{
				if (m == 0)
					ans++;
				else
					m--;
			}
			else
			{
				if (k != 0)
				{
					k--;
					continue;
				}	
				
				if (m != 0)
				{
					m--;
					continue;
				}
				
				ans++;
			}
		}
	cout << ans << endl;
}