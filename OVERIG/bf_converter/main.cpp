#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string str = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	cout << "char* ptr = malloc(100*sizeof(char));" << endl;
	int niv = 0;
	for(int i = 0; i < str.size(); i++)
	{
		for(int j = 0; j < niv; j++) cout << "    ";
		
		if(str.at(i) == '>') cout << "++ptr;" << endl;
		else if(str.at(i) == '<') cout << "--ptr;" << endl;
		else if(str.at(i) == '+') cout << "++(*ptr);" << endl;
		else if(str.at(i) == '-') cout << "--(*ptr);" << endl;
		else if(str.at(i) == '.') cout << "putchar(*ptr);" << endl;
		else if(str.at(i) == ',') cout << "*ptr = getchar();" << endl;
		else if(str.at(i) == '[') { cout << "while(*ptr) {" << endl; niv++; }
		else if(str.at(i) == ']') { cout << "}" << endl; niv--; }
	}
}