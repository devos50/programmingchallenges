#include <iostream>
#include <string>
#include <map>

using namespace std;

void solve(int np)
{
	map<string, int> money;
    string names[10];
    
    for(int i = 0; i < np; i++)
    {
        string name;
        cin >> name;
        names[i] = name;
        money[name] = 0;
    }
    
    // namen uitgelezen - lees uitgaves
	string giver;
    for(int j = 0; j < np; j++)
    {
        cin >> giver;
        int amount, n;
        cin >> amount >> n;
        if(n == 0) continue;
        int each = amount / n;
        for(int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            money[giver] -= each;
            money[name] += each;
        }
    }

    for(int i = 0; i < np; i++)
    {
        cout << names[i] << " " << money[names[i]] << endl;
    }
}

int main()
{
    int n; cin >> n;
	while(true)
	{
		solve(n);
		if(cin >> n) cout << endl;
		else break;
	}
    
    return 0;
}