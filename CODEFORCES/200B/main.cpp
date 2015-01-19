#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int denum = n * 100;
	int num = 0;
	for(int i = 0; i < n; i++) { int s; cin >> s; num += s; }
	
	cout << 100.0 * ((double)num / (double)denum) << endl;
}