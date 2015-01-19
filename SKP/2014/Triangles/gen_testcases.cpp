#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

unsigned long long ans(unsigned long long n)
{
	unsigned long long sum = 0;
	for(unsigned long long i = 1; i <= n; i++)
	{
		sum += (i * (i + 1)) / 2;
	}
	return sum;
}

int main(int argc, char *argv[]) 
{
	srand(clock());
	
	// add testcases 1 - 5
	for(int i = 1; i <= 5; i++)
	{
		stringstream ss;
		ss << i;
		string str = ss.str();
				
		// write the input to the files
		ofstream fout1("testcases/testcase" + str + ".in");
		unsigned long long rnum = i;
		fout1 << rnum;
				
		// write the output to the files
		ofstream fout2("testcases/testcase" + str + ".out");
		fout2 << ans(rnum);
	}
	
	// add totally random testcases
	for(int i = 6; i <= 30; i++)
	{
		stringstream ss;
		ss << i;
		string str = ss.str();
		
		// write the input to the files
		ofstream fout1("testcases/testcase" + str + ".in");
		unsigned long long rnum = rand() % 2000000;
		fout1 << rnum;
		
		// write the output to the files
		ofstream fout2("testcases/testcase" + str + ".out");
		fout2 << ans(rnum);
	}
	
	// add the 2 million testcase
	ofstream fout1("testcases/testcase31.in");
	unsigned long long rnum = 2000000;
	fout1 << rnum;
					
	// write the output to the files
	ofstream fout2("testcases/testcase31.out");
	fout2 << ans(rnum);
}