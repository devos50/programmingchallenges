#include <iostream>
#include <list>
#include <cstdio>

#define maxsolds 100005

using namespace std;

typedef struct Soldier {
	int left, right;
} Soldier;

Soldier soldiers[maxsolds];

int main(int argc, char *argv[]) 
{
	int s, b;
	while(scanf("%d %d",&s,&b) && !(!s && !b))
	{
		for(int i = 1; i <= s; i++)
		{
			Soldier sold; sold.left = i - 1; sold.right = i + 1;
			soldiers[i] = sold;
		}
		soldiers[s].right = 0;
		
		for(int i = 0; i < b; i++)
		{
			int l, r; scanf("%d %d", &l, &r);
			
			int newl = soldiers[l].left;
			if(newl == 0) printf("* ");
			else printf("%d ", newl);
			
			int newr = soldiers[r].right;
			if(newr == 0) printf("*\n");
			else printf("%d\n", newr);
			
			soldiers[newl].right = newr;
			soldiers[newr].left = newl;
		}
		printf("-\n");
	}
}