#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	long long n, m, a; cin >> n >> m >> a;
	
	long long w = n / a;
	if(n % a != 0) w++;
	
	long long h = m / a;
	if(m % a != 0) h++;
	
	cout << h * w << endl;
}