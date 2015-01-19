#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	vector<int> cards;
	int s1 = 0, s2 = 0;
	for(int i = 0; i < n; i++)
	{
		int d; cin >> d;
		cards.push_back(d);
	}
	sort(cards.begin(), cards.end());
	
	bool f_take = true;
	for(int i = n - 1; i >= 0; i--)
	{
		if(f_take) s1 += cards[i];
		else s2 += cards[i];
		
		f_take = !f_take;
	}
	cout << s1 << " " << s2 << endl;
}