#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void print_vector(vector<int> vec)
{
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it;
		if(it + 1 != vec.end()) cout << " ";
	}
	cout << endl;
}

void solve(string l)
{
	istringstream iss(l);
	vector<int> originalVec;
	for (int n; iss >> n; )
	{
		originalVec.push_back(n);
	}
	
	vector<int> sortedVec = originalVec;
	sort(sortedVec.begin(), sortedVec.end());
	// cout << "sorted: ";
	// print_vector(sortedVec);
	
	print_vector(originalVec);
	
	for(int i = sortedVec.size() - 1; i >= 0; i--)
	{
		// print_vector(originalVec);
		
		int target = sortedVec[i];
		// cout << "target: " << target << endl;
		
		// find target in the original vector
		int pos = 0;
		for(int j = 0; j < originalVec.size(); j++)
		{
			if(originalVec[j] == target) { pos = j; break; }
		}
		
		int cmd = originalVec.size() - pos;
		cout << cmd << " ";
		
		// reverse it in the originalVec
		reverse(originalVec.begin(), originalVec.begin() + pos + 1);
		
		// print_vector(originalVec);
		
		// now reverse the whole array
		reverse(originalVec.begin(), originalVec.begin() + i + 1);
		
		cout << originalVec.size() - i << " ";
	}
	
	cout << "0" << endl;
	
	// print_vector(originalVec);
}

int main(int argc, char *argv[]) 
{
	string l; 
	while(getline(cin, l)) solve(l);
}