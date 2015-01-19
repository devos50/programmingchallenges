#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k; cin >> n >> k;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int num; scanf("%d", &num);
		if(num % k == 0) ans++;
	}
	cout << ans << endl;
}