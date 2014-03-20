#include <iostream>
#define MAXN 1000002

bool isHnumber[MAXN];
bool isHPrime[MAXN];
bool isSemiPrime[MAXN];
int hprimes[100000];
int hseminumber[MAXN];
using namespace std;
int numOfHprimes,numOfHsemiprimes;

void init()
{
    for (int i=0;i<MAXN;i++)
    {
        isHnumber[i]=false;
        isHPrime[i]=false;
        isSemiPrime[i]=false;
        hseminumber[i]=0;
    }
    int current=0;
    while (current<MAXN)
    {
        int tmp=current+1;
        if (tmp<MAXN)
        {
            isHnumber[tmp]=true;
            isHPrime[tmp]=true;
        }
        current+=4;
    }
    current=5;
    isHPrime[1]=false;
    numOfHprimes=0;
    while (current<MAXN/2)
    {
        int tmp=current*2;
        numOfHprimes++;
        hprimes[numOfHprimes]=current;
        while (tmp<MAXN/2)
        {
            isHPrime[tmp]=false;
            tmp+=current;
        }
        current++;
        while (current<MAXN/2 && (!isHPrime[current]))
            current++;
    }
    for (int i=1;i<=numOfHprimes;i++)
        if (hprimes[i]<=1001)
        {
            for (int j=i;j<=numOfHprimes;j++)
                if (hprimes[j]<=(MAXN/hprimes[i]+1))
                {
                    int tmp=hprimes[i]*hprimes[j];
                    if (tmp<MAXN && isHnumber[tmp])
                        isSemiPrime[tmp]=true;
                } else break;
        } else break;
    int numOfHsemiprimes=0;
    for (int i=1;i<MAXN;i++)
    {
        if (isSemiPrime[i]) numOfHsemiprimes++;
        hseminumber[i]=numOfHsemiprimes;
    }

}

int main()
{
    init();
    int h;
    cin>>h;
    while (h != 0)
    {
        cout<<h<<' '<<hseminumber[h]<<endl;
        cin>>h;
    }
    return 0;
}
