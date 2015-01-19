#include <iostream>

using namespace std;

int main()
{
    double i,n,k,r,t;
    
    scanf("%lf",&t);
    
    while(t--)
    {
              r=1.00;
              scanf("%lf %lf",&n,&k);
              n=n-1;
              k=k-1;
              if(k>n-k)
                       k=n-k;
              for(i=0;i<k;i++)
              {
                            r=r*((n-i)/(k-i));  
              }
              printf("%.0lf\n",r);
    }
    return 0;
    
}