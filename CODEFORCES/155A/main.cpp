#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int min_score, max_score;
	cin >> min_score;
	max_score = min_score;
	
	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		int score; cin >> score;
		if(score < min_score)
		{
			min_score = score;
			ans++;
		}
		else if(score > max_score)
		{
			max_score = score;
			ans++;
		}
	}
	cout << ans << endl;
}