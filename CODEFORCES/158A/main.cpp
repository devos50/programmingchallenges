#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, k; cin >> n >> k;
	vector<int> scores;
	for(int i = 0; i < n; i++)
	{
		int score; cin >> score;
		scores.push_back(score);
	}
	int s = scores[k - 1];
	
	int curind = 0;
	int ans = 0;
	while(scores[curind] >= s && curind < scores.size())
	{
		if(scores[curind] > 0) ans++;
		curind++;
	}
	cout << ans << endl;
}