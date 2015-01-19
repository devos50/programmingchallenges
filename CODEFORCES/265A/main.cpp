#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string stones; cin >> stones;
	string instructions; cin >> instructions;
	int curpos = 0;
	for(int i = 0; i < instructions.size(); i++)
	{
		if(instructions[i] == stones[curpos]) curpos++;
	}
	cout << curpos + 1 << endl;
}