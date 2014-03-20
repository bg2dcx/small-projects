#include <iostream>
#include <memory.h>
#include <stdlib.h>
#define BVALUE 7500;

using namespace std;



long long dp[3][15001];
int hooks[21],weights[21];

int numOfHooks,numOfWeights;
int longest,heaviest,maxweight;

int main()
{
    cin>>numOfHooks>>numOfWeights;
    longest=0;
    heaviest=0;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=numOfHooks;i++)
    {
           cin>>hooks[i];
           if (abs(hooks[i])>longest)
            longest=abs(hooks[i]);
    }
    for (int i=1;i<=numOfWeights;i++)
    {
         cin>>weights[i];
         heaviest+=weights[i];
    }
    maxweight=longest*heaviest;
    int sum=BVALUE;
    for (int i=1;i<=numOfHooks;i++)
    {
        int tmp=sum+weights[1]*hooks[i];
        dp[0][tmp]=1;
    }
    int current=0;
    int previous=0;
    int lowerBound=BVALUE;
    lowerBound-=maxweight;
    int upperBound=BVALUE;
    upperBound+=maxweight;
    for (int i=2;i<=numOfWeights;i++)
    {
        previous=current;
        current=1-current;
        for (int j=lowerBound;j<=upperBound;j++)
        {
            dp[current][j]=0;
            for (int k=1;k<=numOfHooks;k++)
            {
                int tmp=j-weights[i]*hooks[k];
                if (tmp>=lowerBound && tmp<=upperBound)
                    dp[current][j]+=dp[previous][tmp];
            }
        }
    }

    cout<<dp[current][7500]<<endl;
    return 0;
}
