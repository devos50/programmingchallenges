#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	string s;
	cin >> n >> s;
	int currentTime = 600 * s[0] + 60 * s[1] + 10*s[3] + s[4];
	vector<pair<int, int> > busses;
	for(int i=0; i<n; ++i) {
		cin >> s >> m;
		int time = 600 * s[0] + 60 * s[1] + 10*s[3] + s[4];
		busses.push_back(make_pair(time, m));
	}
	
	int best = 1<<30;
	for(int i=0; i < n; ++i) {
		int time = busses[i].first;
		int tt = busses[i].second;
		if(time < currentTime) {
			time += 24 * 60;
		}
		best = min(best, tt + time - currentTime);
	}
	cout << best << endl;
}

int main(int argc, char *argv[]) {
	int t;
	cin >> t;
	for(int i = 1; i<= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
}