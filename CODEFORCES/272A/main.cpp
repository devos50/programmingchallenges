#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int sum = 0;
	int fings[n]; for(int i = 0; i < n; i++) { cin >> fings[i]; sum += fings[i]; }
	
	int ans = 0;
	for(int i = 1; i <= 5; i++)
	{
		int curf = -1;
		for(int j = 0; j < sum + i; j++)
		{
			curf++;
			if(curf == n + 1) curf = 0;
		}
		if(curf != 0) { ans++; }
	}
	cout << ans << endl;
}