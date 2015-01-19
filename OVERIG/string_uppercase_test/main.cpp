#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	char c = 'c';
	if(c >= 'a' && c <= 'z') cout << "kleine letter";
	else if(c >= 'A' && c <= 'Z') cout << "hoofdletter";
	else cout << "geen hoofdletter/kleine letter";
}