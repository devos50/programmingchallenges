#include <iostream>

using namespace std;

int sorts(int nums[], int n)
{
	int swaps = 0;
	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 1; j <= i; j++)
		{
			if(nums[j-1] > nums[j])
			{
				int temp = nums[j-1];
				nums[j-1] = nums[j];
				nums[j] = temp;
				swaps++;
			}
		}
	}
	return swaps;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(cin >> n)
	{
		int nums[n];
		for(int i = 0; i < n; i++) cin >> nums[i];
		cout << "Minimum exchange operations : " << sorts(nums, n) << endl;
	}
}