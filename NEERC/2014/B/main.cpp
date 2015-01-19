#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k;
	int a = 0, b =0;
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		if(temp > k) {
			a+= temp - k;
		} else {
			b+= k - temp;
		}
	}
	cout << a << " " << b;
}