#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	for(unsigned long long i = 1E9; i <= 1389026623 + 5; i++)
	{
		if(i % 10 != 0) continue;
		if(i % 1000000 == 0) cout << i << endl;
		unsigned long long s = i * i;
		stringstream ss; ss << s;
		string str = ss.str();
		
		if(str[0] == '1' && str[2] == '2' && str[4] == '3' && str[6] == '4' && str[8] == '5' && str[10] == '6' && str[12] == '7' && str[14] == '8' && str[16] == '9' && str[18] == '0')
		{
			cout << i << endl;
			return 0;
		}
	}
}