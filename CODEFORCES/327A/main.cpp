#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int nums[n]; for(int i = 0; i < n; i++) cin >> nums[i];
	
	int maxones = -1;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			int cpy[n]; for(int k = 0; k < n; k++) cpy[k] = nums[k];
			for(int k = i; k <= j; k++) cpy[k] = 1 - cpy[k];
			
			// count ones
			int ones = 0;
			for(int k = 0; k < n; k++)
				if(cpy[k] == 1) ones++;
			if(ones > maxones) maxones = ones;
			
			// if(ones == 23) cout << "i: " << i << ", j: " << j << endl;
		}
	}
	cout << maxones << endl;
}