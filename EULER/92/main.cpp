#include <iostream>

using namespace std;

bool does_end(int i)
{
	int cur = i;
	while(cur != 1 && cur != 89)
	{
		int newnum = 0;
		while(cur != 0) { newnum += (cur % 10) * (cur % 10); cur /= 10; }
		cur = newnum;
		// cout << "cur: " << cur << " ";
	}
	return (cur == 89);
}

int main(int argc, char *argv[]) 
{
	int ans = 0;
	for(int i = 1; i < 10000000; i++)
	{
		if(i % 100000 == 0) cout << "i: " << i << endl;
		if(does_end(i)) ans++;
	}
	cout << ans << endl;
}