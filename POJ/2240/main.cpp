#include <iostream>
#include <stdio.h>
#include <string.h>
#define precision 0.0000001

using namespace std;

struct NAME
{
    char str[50];
};

double dist[31][31];
double spfaPrice[31];
bool inQueue[31];
int changeNum[31];
int spfaQueue[31];
NAME currency[31];
int n,m;

bool isSame(char str1[], char str2[])
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    if (len1!= len2)
        return false;
    for (int i=0;i<len1;i++)
        if (str1[i] != str2[i])
        return false;
    return true;
}

int find_currency(char name[])
{
    for (int i=0;i<n;i++)
        if (isSame(currency[i].str,name))
          return i;
    return -1;
}

bool solve(int num)
{
    memset(inQueue,0,sizeof(inQueue));
    for (int i=0;i<n;i++)
     {
          spfaPrice[i]=0;
          changeNum[i]=0;
     }
    spfaQueue[0]=num;
    int head=0,tail=1;
    spfaPrice[num]=100;
    inQueue[num]=true;
    changeNum[num]=1;
    while (head != tail)
    {
        int current=spfaQueue[head];
        for (int i=0;i<n;i++)
            if (dist[current][i]!=0)
        {
            if (spfaPrice[current]*dist[current][i]-spfaPrice[i]>precision)
            {
                spfaPrice[i]=spfaPrice[current]*dist[current][i];
                changeNum[i]++;
                if (changeNum[i]>n)
                    return true;
                if (!inQueue[i])
                {
                    inQueue[i]=true;
                    spfaQueue[tail]=i;
                    tail=(tail+1)%31;
                }
            }
        }
        head=(head+1)%31;
        inQueue[current]=false;
    }
    return false;
}

int main()
{
    //FILE *fp;
    //fp=fopen("1.txt","r");
    int numOfCases=0;
    while ( scanf("%d",&n) != EOF)
    {
        if (n == 0 ) break;
        for (int i=0;i<n;i++)
            scanf("%s",currency[i].str);
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            char curr1[31],curr2[31];
            double tmp;
            scanf("%s%lf%s",curr1,&tmp,curr2);
            int m1=find_currency(curr1);
            int m2=find_currency(curr2);
            dist[m1][m2]=tmp;
        }
        numOfCases++;
        bool OK=false;
        for (int i=0;i<n;i++)
            if (solve(i))
        {
            cout<<"Case "<<numOfCases<<": Yes"<<endl;
            OK=true;
            break;
        }
        if (!OK)
        {
            cout<<"Case "<<numOfCases<<": No"<<endl;
        }
    }
    return 0;
}
