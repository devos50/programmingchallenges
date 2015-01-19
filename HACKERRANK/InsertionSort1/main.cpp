#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int s; cin >> s;
	int nums[s];
	for(int i = 0; i < s; i++)
	{
		cin >> nums[i];
	}
	
	int v = nums[s-1];
	for(int i = s - 1; i >= 0; i--)
	{
		if(nums[i-1] > v) nums[i] = nums[i-1];
		else { nums[i] = v; break; }
		
		for(int i = 0; i < s; i++) cout << nums[i] << " ";
		cout << endl;
	}
	
	for(int i = 0; i < s; i++) cout << nums[i] << " ";
	cout << endl;
}