#include <iostream>
#include <memory.h>
#define MAXN 32000
using namespace std;

int primes[20000];
bool isPrime[32050];
int answer[20000];
int numOfPrimes, numOfAns;
int n,x;

void get_primes()
{
    for (int i=2;i<MAXN;i++)
        isPrime[i]=true;
    int current=2;
    while (current<(MAXN/2))
    {
        int tmp=current*2;
        while (tmp < MAXN)
        {
            isPrime[tmp]=false;
            tmp+=current;
        }
        current++;
        while (current<(MAXN/2) && !isPrime[current])
            current++;
    }
    numOfPrimes=0;
    for (int i=2;i<MAXN;i++)
        if (isPrime[i])
    {
        primes[numOfPrimes]=i;
        numOfPrimes++;
    }
}

int main()
{
    cin>>n;
    get_primes();
    for (int i=0;i<n;i++)
    {
        cin>>x;
        numOfAns=0;
        for (int i=0;i<numOfPrimes;i++)
            if (primes[i]<=x/2)
        {
            int tmp=x-primes[i];
            if (isPrime[tmp])
            {
                answer[numOfAns]=primes[i];
                numOfAns++;
            }
        } else break;
        cout<<x<<" has "<<numOfAns<<" representation(s)\n";
        for (int i=0;i<numOfAns;i++)
            cout<<answer[i]<<'+'<<x-answer[i]<<endl;
        cout<<endl;
    }
    return 0;
}
