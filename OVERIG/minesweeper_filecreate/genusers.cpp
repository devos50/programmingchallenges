#include <iostream>
#include <sstream>

using namespace std;

string RandomString(int len)
{
   srand(clock());
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   int pos;
   while(str.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    str.erase (pos, 1);
   }
   return str;
}


int main(int argc, char *argv[]) 
{
	for(int i = 0; i < 200; i++)
	{
		string query = "INSERT INTO scores VALUES(";
		
		// generate random username
		query += "'" + RandomString(8) + "', '";
		
		// generate random score
		int randscore = (rand() * i) % 1000;
		stringstream ss; ss << randscore;
		query += ss.str() + "');";
		cout << query << endl;
	}
}