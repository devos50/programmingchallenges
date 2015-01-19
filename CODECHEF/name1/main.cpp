#include <iostream>

using namespace std;

void solve()
{
	string a, b; cin >> a >> b;
	int n; cin >> n;
	
	// make freq maps
	int freq[30]; for(int i = 0; i < 30; i++) freq[i] = 0;
	for(int i = 0; i < a.size(); i++)
		freq[a[i] - 'a']++;
	for(int i = 0; i < b.size(); i++)
		freq[b[i] - 'a']++;
	
	bool pos = true;
	for(int i = 0; i < n; i++)
	{
		string cname; cin >> cname;
		for(int j = 0; j < cname.size(); j++)
		{
			if(freq[cname[j] - 'a'] == 0)
			{
				pos = false;
			}
			freq[cname[j] - 'a']--;
		}
	}
	if(pos) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}