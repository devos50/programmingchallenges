#include <iostream>
#include <fstream>

using namespace std;

int matrix[80][80];
int dp[80][80];

int main(int argc, char *argv[]) 
{
	fstream fin("matrix.txt");
	for(int y = 0; y < 80; y++)
		for(int x = 0; x < 80; x++)
		{
			int num; fin >> num;
			matrix[y][x] = num;
		}
		
	dp[0][0] = matrix[0][0];
	for(int x = 1; x < 80; x++) dp[0][x] = dp[0][x-1] + matrix[0][x];
	for(int y = 1; y < 80; y++) dp[y][0] = dp[y-1][0] + matrix[y][0];
	
	for(int y = 1; y < 80; y++)
	{
		for(int x = 1; x < 80; x++)
		{
			dp[y][x] = min(dp[y-1][x], dp[y][x-1]) + matrix[y][x];
		}
	}
	
	cout << dp[79][79];
}