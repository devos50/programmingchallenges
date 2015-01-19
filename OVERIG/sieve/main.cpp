#include <iostream>

using namespace std;

void sieve(int max) {
	bool sv[max];
	for(int i = 0; i < max; i++) sv[i] = true;
	sv[0] = false, sv[1] = false;
	for(int i = 2; i < max; i++)
		if(sv[i]) {
			for(int k = 2 * i; k < max; k += i)
				sv[k] = false;
		}
}

int main(int argc, char *argv[]) {
	int max = 200;
	sieve(max);
}