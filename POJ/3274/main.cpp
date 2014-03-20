#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define LARGE_PRIME 99983
#define MAXN 100001
using namespace std;

struct NODE
{
    int num;
    NODE *next;
};
//FILE *fp;
int sum[31];
int cows[MAXN][30];
NODE hashtable[LARGE_PRIME];
int numOfCows,numOfFeatures,feature,key,maxrange;
bool allsame,allsameexist;

bool isSame(int num1,int num2)
{
    for (int i=0;i<numOfFeatures;i++)
        if (cows[num1][i] != cows[num2][i])
        return false;
    return true;
}

void insert_hash(int cownumber,int key)
{
    NODE *p=&hashtable[key];
    if (p->num == -1)
    {
        p->num=cownumber;
    } else
    {
        while (true)
        {
            if (isSame(p->num,cownumber))
            {
                if (cownumber-p->num>maxrange)
                    maxrange=cownumber-p->num;
            }
            if (p->next != NULL)
                p=p->next;
             else break;
        }
        NODE *q=(NODE *)malloc(sizeof(NODE));
        p->next=q;
        q->num=cownumber;
        q->next=NULL;
    }
}

int main()
{
    //fp=fopen("lineup.7.in","r");
    scanf("%d%d",&numOfCows,&numOfFeatures);
    allsameexist=false;
    for (int i=0;i<numOfFeatures;i++)
        sum[i]=0;
    maxrange=0;
    for (int i=0;i<LARGE_PRIME;i++)
    {
        hashtable[i].num=-1;
        hashtable[i].next=NULL;
    }
    for (int i=0;i<30;i++)
        cows[0][i]=0;
    insert_hash(0,0);
    for (int i=1;i<=numOfCows;i++)
    {
        scanf("%d",&feature);
        key=0;
        allsame=true;
        for (int j=0;j<numOfFeatures;j++)
        {
            sum[j]+=(feature>>j)&1;
            key+=sum[j]-sum[0];
            cows[i][j]=sum[j]-sum[0];
            if (key !=0) allsame=false;
        }
        if (allsame) allsameexist=true;
        key%=LARGE_PRIME;
        insert_hash(i,key);
    }
    if (maxrange==0)
        if (allsameexist)
          maxrange=1;
    cout<<maxrange<<endl;
    return 0;
}
