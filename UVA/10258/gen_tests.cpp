#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	cout << 5 << endl << endl;
	
	char codes[5] = { 'C', 'I', 'R', 'U', 'E' };
	
	for(int j = 0; j < 5; j++)
	{
		for(int i = 0; i < 20; i++)
		{
			int team = rand() % 10 + 1;
			int problemId = rand() % 9 + 1;
			int time = rand() % 500;
			char randcode = codes[rand() % 5];
			
			cout << team << " " << problemId << " " << time << " " << randcode << endl;
		}
		cout << endl;
	}
}