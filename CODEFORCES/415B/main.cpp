#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	unsigned long long n, a, b; cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
	{
		unsigned long long d; cin >> d;
		cout << (d * a) % b << " ";
	}
	cout << endl;
}