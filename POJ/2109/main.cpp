#include <iostream>
#include <stdio.h>
#include <string.h>
#define BASE 10
#define MAXN 1000000000


using namespace std;

int nump[300];
int numk[300];
int numkoriginal[300];
int n,k,plen,current;
char inputnum[300];
int calcnum[300];
void init(){
    for (int i=0;i<200;i++)
    {
        nump[i]=0;
        numk[i]=0;
    }
}

void create_k_current()
{
    int tmp=0;
    memset(numk,0,sizeof(numk));
    memset(numkoriginal,0,sizeof(numkoriginal));
    int rest=current;
    while (rest>0)
    {
        tmp++;
        numkoriginal[tmp]=rest%BASE;
        rest/=BASE;
    }
    numkoriginal[0]=tmp;
    numk[0]=1;
    numk[1]=1;
}

void multiply(int num1[], int num2[])
{
    memset(calcnum,0,sizeof(calcnum));
    for (int i=1;i<=num1[0];i++)
        for (int j=1;j<=num2[0];j++)
          calcnum[i+j-1]+=num1[i]*num2[j];
    int maxlen=num1[0]+num2[0]-1;
    for (int i=0;i<maxlen;i++)
    {
        calcnum[i+1]+=calcnum[i]/BASE;
        calcnum[i]=calcnum[i]%BASE;
    }
    while (calcnum[maxlen]>BASE)
    {
        calcnum[maxlen+1]=calcnum[maxlen]/BASE;
        calcnum[maxlen]%=BASE;
        maxlen++;
    }
    num1[0]=maxlen;
    for (int i=1;i<=maxlen;i++)
        num1[i]=calcnum[i];
}



int test_k(int exponent)
{
    int rest=exponent;
    while (rest>0)
    {
        if (rest%2>0)
        {
            multiply(numk,numkoriginal);
            rest--;
        }
        if (rest>0)
        {
            multiply(numkoriginal,numkoriginal);
            rest=rest/2;
        }
        if (numk[0]>nump[0] || numkoriginal[0]>nump[0]) return 1;
    }
    if (numk[0]<nump[0]) return -1;
    for (int i=plen;i>0;i--)
    {
        if (numk[i]>nump[i]) return 1;
        if (numk[i]<nump[i]) return -1;
    }
    return 0;
}

int main()
{
    while (scanf("%d%s",&n,inputnum) != EOF)
    {
        init();
        plen=strlen(inputnum);
        for (int i=1;i<=plen;i++)
            nump[i]=inputnum[plen-i]-'0';
        nump[0]=plen;
        int lowerbound=1;
        int upperbound=MAXN;
        while (lowerbound<=upperbound)
        {
            current=(lowerbound+upperbound)/2;
            create_k_current();
            int feedback=test_k(n);
            if (feedback == 0) break;
            if (feedback>0)
                upperbound=current-1;
            else
                lowerbound=current+1;
        }
        //current=19;
        //create_k_current();
        //int feedback=test_k(n);
        cout<<current<<endl;
    }
    return 0;
}
