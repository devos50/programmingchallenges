#include <iostream>
#include <map>

using namespace std;

void solve()
{
	map<char, int> prices;
	int k; cin >> k;
	while(k--)
	{
		char c; int price; cin >> c >> price;
		prices[c] = price;
	}
	
	int m; cin >> m;
	int price = 0;
	string str;
	getline(cin, str);
	while(m--)
	{
		string line; getline(cin, line);
		for(int i = 0; i < line.size(); i++)
		{
			if(prices.find(line.at(i)) != prices.end())
				price += prices[line.at(i)];
		}
	}
	// cout << price << endl;
	
	int before = price / 100;
	cout << before << ".";
	int after = price % 100;
	if(after < 10) cout << "0";
	cout << after << "$" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}