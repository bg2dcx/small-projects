#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 1000001
using namespace std;
char numK[101];
long long numkk[101];
int numl;
int len,numlen;
int primes[80000];
int numOfPrimes;
bool isPrime[MAXN];
void init()
{
    for (int i=0;i<101;i++)
        numK[i]=0;
}

void get_primes()
{
    for (int i=0;i<MAXN;i++)
        isPrime[i]=true;
    isPrime[0]=false;
    isPrime[1]=false;
    int current=2;
    while (current<MAXN)
    {
        int tmp=current*2;
        while (tmp<MAXN)
        {
            isPrime[tmp]=false;
            tmp+=current;
        }
        current++;
        while (current<MAXN && (!isPrime[current]))
            current++;
    }
    numOfPrimes=0;
    for (int i=2;i<MAXN;i++)
        if (isPrime[i])
    {
        numOfPrimes++;
        primes[numOfPrimes]=i;
    }
}
bool divisible(long long number)
{
    long long mod=0;
    for (int i=numlen-1;i>=0;i--)
    {
        mod=(mod*1000000000000+numkk[i])%number;
    }
    if (mod == 0) return true;
    else return false;
}

void solve()
{
    numlen=0;
    int tmp=len-1;
    while (tmp>=0)
    {
        long long num=0;
        for (int i=11;i>=0;i--)
            if (tmp-i>=0)
            num=num*10+numK[tmp-i]-'0';
        numkk[numlen]=num;
        numlen++;
        tmp=tmp-12;
    }
    int current=1;
    while (current<=numOfPrimes && primes[current]<numl)
    {
        if (divisible(primes[current]))
        {
            cout<<"BAD "<<primes[current]<<endl;
            return;
        }
        current++;
    }
    cout<<"GOOD"<<endl;
}

int main()
{
    get_primes();
    scanf("%s%d",numK,&numl);
    while (numl != 0)
    {
        len=strlen(numK);
        solve();
        init();
        scanf("%s%d",numK,&numl);

    }
    return 0;
}
