#include <iostream>

using namespace std;

bool used[17];
int n;
int p[55],a[55],b[55];

double rec(int ind){
		if(ind>=n) return 1;
		double res = 0;
		if(!used[a[ind]]){
			used[a[ind]] = true;
			res += (p[ind]/100.0)*rec(ind+1);
			used[a[ind]] = false;
		}
		if(!used[b[ind]]){
			used[b[ind]] = true;
			res += ((100-p[ind])/100.0)*rec(ind+1);
			used[b[ind]] = false;
		}
		return res;
	}

void solve()
{
	cin >> n;
	if(n>16){
		cout << "0.0" << endl;
		return;
	}
	
	for(int i = 0; i < 17; i++) used[i] = 0;
	for(int i = 0; i < 17; i++) p[i] = 0;
	for(int i = 0; i < 17; i++) a[i] = 0;
	for(int i = 0; i < 17; i++) b[i] = 0;
	
	for(int i=0;i<n;i++){
		cin >> p[i] >> a[i] >> b[i];
	}
	cout << rec(0) << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}