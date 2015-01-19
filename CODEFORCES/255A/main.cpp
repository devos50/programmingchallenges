#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	int chest = 0, biceps = 0, back = 0;
	int curtraining = 0;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if(curtraining == 0) chest += a;
		else if(curtraining == 1) biceps += a;
		else if(curtraining == 2) back += a;
		
		curtraining++;
		if(curtraining == 3) curtraining = 0;
	}
	
	if(chest > biceps && chest > back) cout << "chest" << endl;
	else if(biceps > chest && biceps > back) cout << "biceps" << endl;
	else cout << "back" << endl;
}