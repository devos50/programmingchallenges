#include <iostream>
#include <cmath>

using namespace std;

bool isComposite(int num)
{
	for(int i = 2; i < num; i++)
		if(num % i == 0) return true;
	return false;
}

bool isPrime(int num)
{
	if(num == 1 || num == 0 || num < 0) return false;
	
	for(int i = 2; i*i <= num; i++)
		if(num % i == 0) return false;
		
	return true;
}

int main(int argc, char *argv[]) 
{
	int curNum = 1;
	while(true)
	{
		if(isComposite(curNum) && curNum % 2 == 1)
		{
			int upperbound = sqrt(curNum / 2.0) + 2;
			bool foundsum = false;
			for(int i = 1; i <= upperbound; i++)
			{
				int sum = curNum - 2*i*i;
				if(isPrime(sum))
				{
					// cout << curNum << " = " << sum << " + 2x" << i << "^2" << endl;
					foundsum = true;
				}
			}
			if(!foundsum) break;
		}
		curNum++;
	}
	cout << curNum;
}