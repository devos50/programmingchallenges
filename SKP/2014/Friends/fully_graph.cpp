#include <iostream>

#define N 100

using namespace std;

int main(int argc, char *argv[]) 
{
	cout << N << " " << (N * (N - 1)) / 2 << " " << 1 << endl;
	int c = 0;
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
		{
			cout << i << " " << j << endl;
			c++;
		}
		
	// cout << "c: " << c << endl;
}