#include <iostream>
#include <memory.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

ifstream fin("1.txt");

int price[101];
int spfaprice[101];
int dist[101][101];
int n,m;
int level[101];
int spfaqueue[101];
bool inQueue[101];

int spfa(int maxlevel)
{
    memset(inQueue,0,sizeof(inQueue));
    spfaqueue[0]=1;
    for (int i=1;i<=n;i++)
        spfaprice[i]=price[i];
    spfaprice[1]=0;
    int head=0;
    int tail=1;
    inQueue[1]=true;
    int ans=price[1];
    while (head != tail)
    {
        int current=spfaqueue[head];
        for (int j=1;j<=n;j++)
            if (level[j]<=maxlevel && level[j]>=maxlevel-m && dist[current][j]<0 )
            {
                if (spfaprice[current]+dist[current][j]+price[j] < spfaprice[j])
                {
                    spfaprice[j]=spfaprice[current]+dist[current][j]+price[j];
                    if (spfaprice[j]<ans)
                    {
                        ans=spfaprice[j];
                    }
                    if (!inQueue[j])
                    {
                        spfaqueue[tail]=j;
                        tail=(tail+1)%101;
                        inQueue[j]=true;
                    }
                }
            }
        inQueue[current]=false;
        head=(head+1)%101;
    }
    return ans;
}

int main()
{
    fin>>m>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dist[i][j]=1;
    int cutOffPrice,itemNum;
    for (int i=1;i<=n;i++)
    {
        int numOfSubs;
        fin>>price[i]>>level[i]>>numOfSubs;
        spfaprice[i]=price[i];
        for (int j=0;j<numOfSubs;j++)
        {
            fin>>itemNum>>cutOffPrice;
            dist[i][itemNum]=cutOffPrice-price[i];
        }
    }
    int ans=price[1];
    int tmp=0;
    for (int i=level[1];i<=level[1]+m;i++)
    {
         tmp=spfa(i);
         if (tmp+price[1]<ans)
            ans=tmp+price[1];
    }

    cout<<ans<<endl;
    return 0;
}
