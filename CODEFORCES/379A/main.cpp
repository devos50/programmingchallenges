#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int a, b; cin >> a >> b;
	int r = 0, u = 0;
	    while (a > 0) {
	        a --;
	        r += 1;
	        u ++;
	        if (u >= b) {
	            a ++;
	            u -= b;
	        }
	    }
	    cout << r << endl;
}