#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int bags = n * n;
	
	int pt = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n / 2; j++)
		{
			cout << pt << " " << bags - pt + 1 << " ";
			pt++;
		}
		cout << endl;
	}
}