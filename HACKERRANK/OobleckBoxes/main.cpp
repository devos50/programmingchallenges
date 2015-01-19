#include <iostream>
#include <vector>

using namespace std;

void count(int target, vector<long long> coins)
{
	long long out[target]; for(int i = 0; i < target; i++) out[i] = 0;
	
	for (int a = 0; a < coins.size(); a++)
	{
		for (int b = coins[a] - 1; b < target; b++)
	    {
	     	if (b - coins[a] == -1) out[b] += 1;
	        else
            {
                out[b] += out[b - coins[a]];
                out[b] %= 1000000007;
            }
	    }
	}
	cout << out[target - 1] << endl;
}

int main(int argc, const char * argv[])
{
    vector<long long> coins;
	long long m, n; cin >> m >> n;
	
	if(n == 1) coins.push_back(1);
	else
	{
		long long cur = 1;
		while(cur <= m)
		{
			coins.push_back(cur);
			cur *= n;
		}
	}
	
	count(m, coins);

    return 0;
}
