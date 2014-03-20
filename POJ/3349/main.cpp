#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define LARGE_PRIME 99991
#define MAXN 100001
#define MAXLEN  10000000

using namespace std;

struct Node{
int num;
Node* next;
};

Node hashtable[LARGE_PRIME];
int snowflake[MAXN][6];
int numOfFlakes,lengthSum;

int create_flake(int flakeNum, int armNum, int tmp[])
{
    long long sum=1;
    for (int i=0;i<6;i++)
    {
        snowflake[flakeNum][i]=tmp[(armNum+i)%6];
        if (tmp[i]!=0)
            sum=(sum*tmp[i])%LARGE_PRIME;
    }
    return (int)(sum%LARGE_PRIME);
}

bool similar(int num1, int num2)
{
    bool same=true;
    bool countersame=true;
    for (int st=0;st<6;st++)
    {
        same=true;
        countersame=true;
        for (int i=0;i<6;i++)
        {
        if (snowflake[num1][(st+i)%6] != snowflake[num2][i])
            same=false;
        if (snowflake[num1][(st+i)%6] != snowflake[num2][(6-i)%6])
            countersame=false;
        }
        if (same || countersame) return true;
    }
    return false;
}

bool insert_hash(int flakeNum, int lenSum)
{
    Node *q=&hashtable[lenSum];
    if (q->num==-1)
    {
        q->num=flakeNum;
    } else{
        while (true)
        {
            if (similar(flakeNum,q->num))
                return true;
            if (q->next != NULL)
                q=q->next;
              else break;
        }
        Node *p=(Node*)malloc(sizeof(Node));
        q->next=p;
        p->num=flakeNum;
        p->next=NULL;
    }
    return false;
}
int main()
{
    for (int i=0;i<LARGE_PRIME;i++)
    {
        hashtable[i].next=NULL;
        hashtable[i].num=-1;
    }
    scanf("%d",&numOfFlakes);
    bool findAns=false;
    for (int i=0;i<numOfFlakes;i++)
    {
        int tmp[6];
        int minlen=MAXLEN;
        int minnum=-1;
        for (int j=0;j<6;j++)
        {
            scanf("%d",&tmp[j]);
            if (tmp[j]<minlen)
            {
                minlen=tmp[j];
                minnum=j;
            }
        }
        lengthSum=create_flake(i,minnum,tmp);
        findAns=insert_hash(i,lengthSum);
        if (findAns)
        {
            cout<<"Twin snowflakes found."<<endl;
            return 0;
        }
    }
    cout<<"No two snowflakes are alike."<<endl;
    return 0;
}
