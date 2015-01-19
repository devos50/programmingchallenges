#include <iostream>
#include <cmath>

using namespace std;

bool is_perfect_square(int n) 
{
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

int sols(int m)
{
	int ans = 0;
	for(int w = 1; w <= m; w++)
	{
		for(int l = 1; l <= w; l++)
		{
			for(int h = 1; h <= l; h++)
			{
				long long d = w * w + (l + h) * (l + h);
				// cout << "d: " << d << endl;
				if(is_perfect_square(d)) ans++;
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) 
{
	cout << sols(1818);
}