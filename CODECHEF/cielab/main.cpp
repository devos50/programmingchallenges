#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int a, b; cin >> a >> b;
	int ans = a - b;
	if(ans % 10 == 9) ans--;
	else ans++;
	cout << ans << endl;
}