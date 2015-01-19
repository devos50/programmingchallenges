#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	
	// create upper half
	for(int i = 0; i < n; i++)
	{
		int spaces = (n - i) * 2;
		for(int j = 0; j < spaces; j++) cout << " ";
		
		int nums = i * 2 + 1;
		for(int j = 0; j < nums - 1; j++)
		{
			int num = nums / 2 - abs(j - (nums / 2));
			cout << num << " ";
		}
		cout << "0" << endl;
	}

	// create middle part
	for(int j = 0; j < n * 2; j++)
	{
		int num = n - abs(j - n);
		cout << num << " ";
	}
	cout << "0" << endl;
	
	// create lower half
	for(int i = n - 1; i >= 0; i--)
	{
		int spaces = (n - i) * 2;
		for(int j = 0; j < spaces; j++) cout << " ";
		
		int nums = i * 2 + 1;
		for(int j = 0; j < nums - 1; j++)
		{
			int num = nums / 2 - abs(j - (nums / 2));
			cout << num << " ";
		}
		cout << "0" << endl;
	}
}