/*
 ID: mdmarti1
 PROG: checker
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int n;
int board[13*13];
int temp = 0;
vector<vector<int> > solutions;

bool queenincolumn[13];
bool diag1[1400];
bool diag2[1400];

bool canPlace(int x, int y)
{
	// check y
	if(queenincolumn[x]) return false;
	int diag1x = x - min(x, y); int diag1y = y - min(x, y);
	if(diag1[diag1x * 100 + diag1y]) return false;
	int diag2x = x + min(y, n - x - 1); int diag2y = y - min(y, n - x - 1);
	if(diag2[diag2x * 100 + diag2y]) return false;
	
	return true;
}

void rec(int row)
{
	if(row == n) 
	{
		temp++;
		if(solutions.size() == 3) return;
		vector<int> solution;
		
		for(int y = 0; y < n; y++)
			for(int x = 0; x < n; x++)
				if(board[y * n + x]) 
					solution.push_back(x+1);
		solutions.push_back(solution);
		return; 
	}
	
	for(int x = 0; x < n; x++) // iterate over every column in row row
	{
		if(!queenincolumn[x] && !diag1[x - row + 13] && !diag2[x + row])
		{
			board[row * n + x] = true;
			queenincolumn[x] = true; diag1[x - row + 13] = true; diag2[x + row] = true;
			rec(row + 1);
			board[row * n + x] = false;
			queenincolumn[x] = false; diag1[x - row + 13] = false; diag2[x + row] = false;
		}
	}
}

int main()
{
    ofstream fout ("checker.out");
    ifstream fin ("checker.in");
	
	fin >> n;
	
	for(int i = 0; i < n*n; i++) board[i] = false;
	for(int i = 0; i < n; i++) queenincolumn[i] = false;
	
	rec(0);
	
	cout << "n: " << n << ", sol: " << temp;
	for(vector<vector<int> >::iterator it = solutions.begin(); it != solutions.end(); it++)
	{
		vector<int> solution = *it;
		for(vector<int>::iterator it = solution.begin(); it != solution.end(); it++)
		{
			fout << *it;
			if(it + 1 != solution.end()) fout << " ";
		}
		fout << endl;
	}
	fout << temp << endl;
	
    return 0;
}