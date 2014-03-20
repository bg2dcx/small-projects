#include <iostream>
#include <stdio.h>
#include <string.h>
#define BASE 32
#define MAXORDER 12
using namespace std;
int totalNum;
int maxn[MAXORDER];
int roundup(int m_size)
{
    int order=0;
    int current=BASE;
    while (m_size > current)
    {
        order++;
        current=current<<1;
    }
    return order;
}

int main()
{
    FILE *fp;
    fp=fopen("5.trace","r");
    char command[20];
    int arg1,arg2;
    memset(maxn,0,sizeof(maxn));
    fscanf(fp,"%d",&totalNum);
    for (int i=0;i<totalNum;i++)
    {
        fscanf(fp,"%s",command);
        if (strcmp(command,"REQUEST") == 0)
        {
            fscanf(fp,"%d %d",&arg1,&arg2);
            maxn[roundup(arg2+8)]++;
        } else
            fscanf(fp,"%*d");
    }
    for (int i=0;i<MAXORDER;i++)
        cout<<"Order "<<i<<" : "<<maxn[i]<<endl;
    return 0;
}
