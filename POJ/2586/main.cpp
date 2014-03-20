#include <iostream>
#include <stdio.h>

using namespace std;
int s, d;
int months[12];
long total;
int now;
int main()
{
  while (scanf("%d%d",&s,&d) != EOF)
  {
    for (int i=0;i<12;i++) months[i]=s;
    total=5*s;
    now=5;
    while (total > 0)
    {
        now--;
        total-=s;
        months[now]=-d;
        total-=d;
    }
    for (now=5;now < 12; now++)
    {
        total=total-months[now-5]+months[now];
        if (total > 0) {
            months[now]=-d;
            total=total-s-d;
        }
    }
    total=0;
    for (int i=0;i<12;i++) total+=months[i];
    if (total >0 ) cout<<total<<endl;
     else cout<<"Deficit"<<endl;
  }
    return 0;
}
