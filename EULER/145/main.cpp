#include <iostream>

using namespace std;

bool is_odd(int n)
{
	while(n != 0)
	{
		int d = n % 10; n /= 10;
		if(d % 2 == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) 
{
	int cnt = 0;
	for(int a = 1; a <= 9; a++)
		for(int b = 1; b <= 9; b++)
		{
			int sum = a + b;
			cout << "sum: " << sum << ", odd: " << is_odd(sum) << endl;
			if(is_odd(sum) && sum % 2 == 1 && sum > 10) cnt++;
		}
	cout << cnt << endl;
}