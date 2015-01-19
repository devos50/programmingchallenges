#include <iostream>
#include <map>

using namespace std;

int main()
{   
    map<int, int> mapi;
    int n, m, ans = 0, a, b;
    cin >> n >> m;
    if(n == m + 1) ans = 1;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;

        if(mapi.find(a) != mapi.end() && mapi.find(b) != mapi.end()) ans = 0;
        
        mapi[a] = 1;
        mapi[b] = 1;
    }

    if(ans == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}