#include <iostream>

using namespace std;

string names[5] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

void print_name(int n)
{
	int qsize = 1;
	int curind = 1;
	while(curind <= n)
	{
		curind += 5 * qsize;
		qsize *= 2;
	}
	qsize /= 2;
	curind -= 5 * qsize;
	
	int v = n - curind;
	// cout << "cur ind: " << curind << endl;
	cout << names[v / qsize] << endl;
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	print_name(n);
	// for(int i = 1; i < 100; i++) print_name(i);
}