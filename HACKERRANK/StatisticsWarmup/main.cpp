#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double nums[2505];
double n;

double mean()
{
	double sum;
	for(int i = 0; i < n; i++) sum += nums[i];
	return sum / n;
}

double med()
{
	vector<double> v_nums;
	for(int i = 0; i < n; i++) v_nums.push_back(nums[i]);
	sort(v_nums.begin(), v_nums.end());
	if((int)n % 2 == 1) return v_nums[n / 2];
	else return (v_nums[n / 2 - 1] + v_nums[n / 2]) / 2;
}

int main(int argc, char *argv[]) 
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> nums[i];
	
	cout << mean() << endl;
	cout << med() << endl;
}