//
//  main.cpp
//  Euler31
//
//  Created by M.A. de Vos on 09-09-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int dp[105][105];
bool isPrime[1000005];

int count(vector<int> s, int m, int n)
{
    // if n is 0, there is 1 solution (empty set)
    if(n == 0)
        return 1;
    // if n is below zero, there is no solution
    else if(n < 0)
        return 0;
    
    // if the amount of coins <= 0 and the sum is 1 or higher, there are not solutions
    if(m <= 0 && n >= 1)
        return 0;

	if(dp[m][n] != -1) return dp[m][n];

	if(dp[m-1][n] == -1) dp[m-1][n] = count(s, m - 1, n);
	if(dp[m][n - s[m-1]] == -1) dp[m][n - s[m-1]] = count(s, m, n - s[m-1]);
	
	return count(s, m - 1, n) + count(s, m, n - s[m-1]);
}

void sieve()
{
	for(int i = 2; i <= 1000000; i++) isPrime[i] = true;
	
	for(int i = 2; i*i <= 1000000; i++)
	{
		if(isPrime[i])
		{
			for(int j = i; i*j <= 1000000; j++) isPrime[i*j] = false;
		}
	}
}

int main(int argc, const char * argv[])
{
	sieve();
	
    vector<int> numbers;

	int cur = 1;
	while(true)
	{
		numbers.clear();
		for(int i = 2; i < cur; i++) if(isPrime[i]) numbers.push_back(i);
		
		// clear dp array
		for(int i = 0; i < 105; i++)
			for(int j = 0; j < 105; j++)
				dp[i][j] = -1;
		
		int sol = count(numbers, numbers.size(), cur);
		if(sol > 5000)
		{
			cout << cur;
			break;
		}
		cur++;
	}
    return 0;
}

