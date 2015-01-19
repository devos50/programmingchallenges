#include <iostream>
#include <vector>
#include <algorithm>

#define MOVES 500000000

using namespace std;

int curpos = 0;
long long times_finished[40];
int ch_stack[16];
int cc_stack[16];

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main(int argc, char *argv[]) 
{
	srand(clock());
	for(int i = 0; i < 40; i++) times_finished[i] = 0;
	
	// shuffle stacks
	for(int i = 0; i < 16; i++) { ch_stack[i] = i; cc_stack[i] = i; };
	
	for(int i = 0; i < 500; i++)
	{
		int c1 = rand() % 16; int c2 = rand() % 16;
		int tmp = ch_stack[c1];
		ch_stack[c1] = ch_stack[c2];
		ch_stack[c2] = tmp;
		
		c1 = rand() % 16; c2 = rand() % 16;
		tmp = cc_stack[c1];
		cc_stack[c1] = cc_stack[c2];
		cc_stack[c2] = tmp;
	}
	
	int doubles = 0;
	
	for(int i = 0; i < MOVES; i++)
	{
		int num1 = rand() % 4 + 1;
		int num2 = rand() % 4 + 1;
		if(num1 == num2) doubles++;
		else doubles = 0;
		
		if(doubles == 3) // three doubles -> go to jail
		{
			doubles = 0;
			curpos = 10;
			times_finished[curpos]++;
			continue;
		}
		
		curpos += (num1 + num2);
		curpos %= 40;
		
		if(curpos == 30)
		{
			curpos = 10;
			times_finished[curpos]++;
			continue;
		}
		
		if(curpos == 2 || curpos == 17 || curpos == 33) // community chest
		{
			int card = cc_stack[0]; for(int i = 1; i < 16; i++) cc_stack[i-1] = cc_stack[i];
			cc_stack[15] = card;
			
			if(card == 0) curpos = 10;
			else if(card == 1) curpos = 0;
		}
		else if(curpos == 7 || curpos == 22 || curpos == 36) // chance card
		{
			int card = ch_stack[0]; for(int i = 1; i < 16; i++) ch_stack[i-1] = ch_stack[i];
			ch_stack[15] = card;
						
			if(card == 0) curpos = 0;
			else if(card == 1) curpos = 10;
			else if(card == 2) curpos = 11;
			else if(card == 3) curpos = 24;
			else if(card == 4) curpos = 39;
			else if(card == 5) curpos = 5;
			else if(card == 6 || card == 7) // next R
			{
				if(curpos == 7) curpos = 15;
				else if(curpos == 22) curpos = 25;
				else if(curpos == 36) curpos = 5;
			}
			else if(card == 8) // next U
			{
				if(curpos == 7 || curpos == 36) curpos = 12;
				else if(curpos == 22) curpos = 28;
			}
			else if(card == 9) curpos -= 3;
		}
		
		times_finished[curpos]++;
	}
	
	vector<pair<int, int> > vec;
	for(int i = 0; i < 40; i++)
		vec.push_back(make_pair(i, times_finished[i]));
	
	sort(vec.begin(), vec.end(), comp);
	cout << "ANS: " << endl;
	for(int i = 0; i < 40; i++)
	{
		cout << vec[i].first << " => " << vec[i].second << endl;
	}
}