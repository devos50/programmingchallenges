#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	fstream file("trainingdata.txt");
	string s;
	while(file >> s) cout << "points(" << s << ")" << endl;
}