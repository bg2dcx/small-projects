#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point
{
    double left;
    double right;

}p[5012];
bool cmp(Point a,Point b)
{
    return a.left<b.left;
}
int main()
{
   int  i,j,n,m;
   int r;
   int o=0;
   while(~scanf("%d%d",&n,&r),n,r)
   {
     int a,b;
     bool flag=true;

     for(i=0;i<n;i++)
     {
     scanf("%d%d",&a,&b);
     if(abs(b)>r)
      {
            flag=false;
      }
      p[i].left=a*1.000-sqrt(r*r*1.00-b*b*1.0000);
      p[i].right=a*1.000+sqrt(r*r*1.00-b*b*1.0000);
     }
      printf("Case %d: ",++o);
     if(flag==false)
       puts("-1");
     else
     {
       sort(p,p+n,cmp);
       int cnt=1;
       double temp=p[0].right;
       for(i=1;i<n;i++)
       {
            if(p[i].right<temp)
            {
                temp=p[i].right;
            }
            else if(p[i].left>temp)
            {
                cnt++;
                temp=p[i].right;
            }
       }
       printf("%d\n",cnt);
     }
   }
}
