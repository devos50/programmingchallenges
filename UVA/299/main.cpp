#include <iostream>

using namespace std;

void solve()
{
	int nums; cin >> nums;
	int num[nums];
	for(int i = 0; i < nums; i++) cin >> num[i];
	
	int swaps = 0;
	for(int i = 0; i < nums; i++)
	{
		for(int j = 1; j < nums - i; j++)
		{
			if(num[j-1] > num[j])
			{
				swaps++;
				int tmp = num[j];
				num[j] = num[j-1];
				num[j-1] = tmp;
			}
		}
	}
	cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}