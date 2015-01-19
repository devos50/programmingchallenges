#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, m; cin >> n >> m;
	int lights[n]; for(int i = 0; i < n; i++) lights[i] = -1;
	
	for(int i = 0; i < m; i++)
	{
		int button; cin >> button; button--;
		for(int j = button; j < n; j++)
		{
			if(lights[j] == -1) // turn light off
			{
				lights[j] = button;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << lights[i] + 1 << " ";
	}
	cout << endl;
}