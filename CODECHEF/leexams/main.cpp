#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
double ans;
vector<pair<int, pair<int, int> > > nums;

void rec(int cur, set<int> curnums, double percentage)
{
	if(cur == n)
	{
		ans += percentage;
		return;
	}
	
	int p = nums[cur].first;
	int a = nums[cur].second.first;
	int b = nums[cur].second.second;
	
	if(curnums.find(a) == curnums.end()) // if curnums does not contain a
	{
		curnums.insert(a);
		rec(cur + 1, curnums, percentage * (double)((double)p / 100.0));
		curnums.erase(a);
	}
	if(curnums.find(b) == curnums.end()) // if curnums does not contain b
	{
		curnums.insert(b);
		rec(cur + 1, curnums, percentage * (double)((double)(100 - p) / 100.0));
		curnums.erase(b);
	}
}

void solve()
{
	ans = 0.0;
	nums.clear();
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int p, a, b; cin >> p >> a >> b;
		nums.push_back(make_pair(p, make_pair(a, b)));
	}
	
	set<int> s;
	rec(0, s, 1.0);
	cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}