#include <iostream>

using namespace std;

void solve(int n)
{
	int a[n]; for(int i = 0; i < n; i++) { cin >> a[i]; a[i]--; }
	
	bool isAmbig = true;
	for(int i = 0; i < n; i++)
	{
		int key = i;
		int val = a[i];
		if(!(a[key] == val && a[val] == key)) { isAmbig = false; break; }
	}
	
	if(isAmbig) cout << "ambiguous" << endl;
	else cout << "not ambiguous" << endl;
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	while(n != 0) { solve(n); cin >> n; }
}