#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	string s; cin >> s;
	
	vector<int> l_num, r_num;
	for(int i = 0; i < s.size() / 2; i++)
		l_num.push_back(s[i] - '0');
	for(int i = s.size() / 2; i < s.size(); i++)
		r_num.push_back(s[i] - '0');
		
	sort(l_num.begin(), l_num.end());
	sort(r_num.begin(), r_num.end());
	
	bool higher_pos = true;
	bool lower_pos = true;
	for(int i = 0; i < l_num.size(); i++)
	{
		if(l_num[i] < r_num[i]) higher_pos = false;
		else if(l_num[i] > r_num[i]) lower_pos = false;
		else { lower_pos = false; higher_pos = false; }
	}
	
	if(higher_pos || lower_pos) cout << "YES" << endl;
	else cout << "NO" << endl;
}