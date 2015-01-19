#include <iostream>
#include <pthread.h>

#define N 1E10
#define THREADS 10
#define MIN(a,b,c,d,e) min((a), min((b), min((c), min((d), (e)))));

using namespace std;

int a;

void rec(string digs, int niv)
{
	// create a used table
	bool used[11];
	for(int i = 0; i < 11; i++) used[i] = false;
	for(int i = 0; i < digs.size(); i++) used[digs[i] - '0'] = true;
	
	if(niv == 5) 
	{
		int sum1 = (digs[0] - '0') + (digs[1] - '0') + (digs[2] - '0');
		int sum2 = (digs[3] - '0') + (digs[2] - '0') + (digs[4] - '0');
		if(sum1 != sum2) return;
	}
	if(niv == 7)
	{
		int sum1 = (digs[3] - '0') + (digs[2] - '0') + (digs[4] - '0');
		int sum2 = (digs[5] - '0') + (digs[4] - '0') + (digs[6] - '0');
		if(sum1 != sum2) return;
	}
	if(niv == 9)
	{
		int sum1 = (digs[7] - '0') + (digs[6] - '0') + (digs[8] - '0');
		int sum2 = (digs[5] - '0') + (digs[4] - '0') + (digs[6] - '0');
		if(sum1 != sum2) return;
	}
	if(niv == 10)
	{
		int sum1 = (digs[0] - '0') + (digs[1] - '0') + (digs[2] - '0');
		int sum2 = (digs[9] - '0') + (digs[8] - '0') + (digs[1] - '0');
		if(sum1 == sum2 && (digs[0] == ':' || digs[3] == ':' || digs[7] == ':' || digs[5] == ':' || digs[9] == ':')) 
		{
			cout << "correct: " << digs << endl;
			
			int minNum = MIN(digs[0], digs[3], digs[5], digs[7], digs[9]);
			cout << "min num: " << minNum - '0' << endl;
		}
		
		return;
	}
	
	for(int i = 1; i <= 10; i++)
	{
		string cpy = digs; cpy.push_back('0' + i);
		if(used[i]) continue;
		
		rec(cpy, niv + 1);
	}
}

void *doSomething(void *beginnum)
{
	rec("", 0);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) 
{
	pthread_t threads[THREADS];
	int rc;
	rc = pthread_create(&threads[0], NULL, doSomething, (void *)0);
	/*
	for(int i = 0; i < THREADS; i++)
	{
		cout << "creating thread, " << i << endl;
		long beginnum = i * (long)(N / THREADS);
		cout << "beginnum: " << beginnum << endl;
		rc = pthread_create(&threads[i], NULL, doSomething, (void *)beginnum);
		
		if(rc) cout << "unable to create thread, " << rc << endl;
	}
	*/
	pthread_exit(0);
}