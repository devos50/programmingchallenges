#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef struct Number {
	int num;
	int type; // 0 = triangle, 1 = square, 2 = pentagonal, 3 = hexagonal, 4 = heptagonal, 5 = octagonal
	int added;
} Number;

vector<Number> numbers;

void genNums()
{
	for(int i = 0; i < 150; i++)
	{
		Number number1, number2, number3, number4, number5, number6;
		int num = i*(i+1)/2; if(num >= 1000 && num < 10000) { number1.num = num; number1.type = 1; number1.added = false; numbers.push_back(number1); } 
		num = i*i; if(num >= 1000 && num < 10000) { number2.num = num; number2.type = 2; number2.added = false; numbers.push_back(number2); }
		num = i*(3*i-1)/2; if(num >= 1000 && num < 10000) { number3.num = num; number3.type = 3; number3.added = false; numbers.push_back(number3); }
		num = i*(2*i-1); if(num >= 1000 && num < 10000) { number4.num = num; number4.type = 4; number4.added = false; numbers.push_back(number4); }
		num = i*(5*i-3)/2; if(num >= 1000 && num < 10000) { number5.num = num; number5.type = 5; number5.added = false; numbers.push_back(number5); }
		num = i*(3*i-2); if(num >= 1000 && num < 10000) { number6.num = num; number6.type = 6; number6.added = false; numbers.push_back(number6); }
	}
}

int prefix(int num)
{
	return num / 100;
}

int suffix(int num)
{
	int suffix = num % 10; num /= 10;
	suffix += 10 * (num % 10);
	return suffix;
}

void rec(vector<Number> cur, bool added[])
{
	cout << "current sequence: ";
	for(vector<Number>::iterator it = cur.begin(); it != cur.end(); it++) cout << it->num << " ";
	cout << endl;
	
	if(cur.size() == 6)
	{
		cout << cur[0].num + cur[1].num + cur[2].num + cur[3].num + cur[4].num + cur[5].num;
		exit(0);
	}
	
	int lastnum = (cur.size() == 0) ? 0 : cur.back().num;
	int suff = suffix(lastnum);
	
	for(vector<Number>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		int pre = prefix(it->num);
		if((pre == suff && !it->added) || cur.size() == 0)
		{
			if(added[it->type]) continue;
			if(cur.size() == 5) // check if the last numbers equals the first numbers
			{
				int prefirst = prefix(cur.front().num);
				int sufcur = suffix(it->num);
				if(sufcur != prefirst) continue;
			}
			it->added = true;
			added[it->type] = true;
			cur.push_back(*it);
			rec(cur, added);
			cur.pop_back();
			it->added = false;
			added[it->type] = false;
		}
	}
}

int main(int argc, char *argv[]) 
{
	genNums();
	bool added[6]; for(int i = 0; i < 6; i++) added[i] = false;
	rec(vector<Number>(), added);
}