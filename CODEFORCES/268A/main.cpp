#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int home_colors[n], guest_colors[n];
	for(int i = 0; i < n; i++) cin >> home_colors[i] >> guest_colors[i];
	
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(home_colors[i] == guest_colors[j]) ans++;
		}
	}
	cout << ans << endl;
}