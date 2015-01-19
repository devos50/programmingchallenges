#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int sum = 0;
	int t[n]; for(int i = 0; i < n; i++) { cin >> t[i]; sum += t[i]; }
	int ans = sum;
	
	int even_sum = 0;
	for(int i = 0; i < n; i += 2) even_sum += t[i];
	if(ans - even_sum > ans) ans -= even_sum;
	
	int odd_sum = 0;
	for(int i = 1; i < n; i += 2) odd_sum += t[i];
	if(ans - odd_sum > ans) ans -= odd_sum;
	
	cout << ans << endl;
}