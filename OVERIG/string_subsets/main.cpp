#include <iostream>
#include <vector>

using namespace std;

vector<string> allsubsets;

void subsets(string word, string cur, int niv)
{
	if(niv == word.size())
	{	
		allsubsets.push_back(cur);
		return;
	}
	subsets(word, cur + word[niv], niv + 1);
	subsets(word, cur, niv + 1);
}

int main(int argc, char *argv[]) 
{
	subsets("testje", "", 0);
}