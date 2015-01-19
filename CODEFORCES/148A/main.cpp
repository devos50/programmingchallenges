#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
	bool arr[d+1]; for(int i = 0; i <= d; i++) arr[i] = false;
	
	for(int i = k; i <= d; i += k) arr[i] = true;
	for(int i = l; i <= d; i += l) arr[i] = true;
	for(int i = m; i <= d; i += m) arr[i] = true;
	for(int i = n; i <= d; i += n) arr[i] = true;
	
	int ans = 0;
	for(int i = 1; i <= d; i++)
		if(!arr[i]) ans++;
	cout << d - ans << endl;
}