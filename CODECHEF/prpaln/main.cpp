#include <iostream>

using namespace std;

bool plsno(string s, int noemhetleft, int noemhetright){
	while(noemhetleft <= noemhetright){
		if(s[noemhetleft] == s[noemhetright]) { noemhetleft++; noemhetright--; continue; }
		return false;
	}
	return true;
}

void solve()
{
	string s; cin >> s;
	bool b = true;
	
	int left = 0;
	int right = s.size() - 1;
	
	if(s.size() == 2){
		cout << "YES" << endl;
		return;
	}
	
	while(left <= right){
		if(s[left] == s[right]) { left++; right--; continue; }
		
		if(!b){ cout << "NO" << endl; return; }
		
		if(plsno(s, left+1, right) || plsno(s, left, right-1)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return;
	}
	
	cout << "YES" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}