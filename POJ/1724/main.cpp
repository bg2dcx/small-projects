#include <iostream>
#include <stdio.h>
#include <memory.h>
#define INF 10000000
#define MAXN 1000005
using namespace std;

struct ROAD
{
    int st,ed,price,length,nextRoad;
    void get_input()
    {
         scanf("%d%d%d%d",&st,&ed,&length,&price);
    }
};

struct DATA
{
    int distance;
};
struct QueueElement
{
    int cityNum, expenditure;
};

int n,r,maxmoney;

ROAD roads[10001];
int firstRoad[10001];
DATA cities[110][10001];
bool inQueue[110][10001];
QueueElement spfaQueue[MAXN];


int main()
{
    scanf("%d",&maxmoney);
    scanf("%d",&n);
    scanf("%d",&r);
    memset(firstRoad,0,sizeof(firstRoad));
    for (int i=1;i<=n;i++)
    {
       for (int j=0;j<=10000;j++)
        {
            cities[i][j].distance=INF;
            roads[j].nextRoad=-1;
        }
    }
    for (int i=1;i<=r;i++)
     {
          roads[i].get_input();
          int tmp=roads[i].st;
          if (firstRoad[tmp] == 0)
          {
              firstRoad[tmp]=i;
          } else
          {
              int q=firstRoad[tmp];
              while (roads[q].nextRoad!=-1)
                q=roads[q].nextRoad;
              roads[q].nextRoad=i;
          }
     }
    memset(inQueue,0,sizeof(inQueue));
    int head=0,tail=1;
    spfaQueue[0].cityNum=1;
    spfaQueue[0].expenditure=0;
    cities[1][0].distance=0;
    while (head!=tail)
    {
        int current=spfaQueue[head].cityNum;
        int currentPrice=spfaQueue[head].expenditure;
        for (int i=firstRoad[current];i!=-1;i=roads[i].nextRoad)
            if (roads[i].st == current)
        {
            int next=roads[i].ed;
            if (currentPrice+roads[i].price<=maxmoney
                && cities[current][currentPrice].distance+roads[i].length<cities[next][currentPrice+roads[i].price].distance)
            {
                cities[next][currentPrice+roads[i].price].distance=cities[current][currentPrice].distance+roads[i].length;
                if (!inQueue[next][currentPrice+roads[i].price])
                {
                    inQueue[next][currentPrice+roads[i].price]=true;
                    spfaQueue[tail].cityNum=next;
                    spfaQueue[tail].expenditure=currentPrice+roads[i].price;
                    tail=(tail+1)%MAXN;
                }
            }
        }
        inQueue[current][currentPrice]=false;
        head=(head+1)%MAXN;
    }
    int ans=INF;
    for (int i=0;i<=maxmoney;i++)
        if (cities[n][i].distance<ans)
            ans=cities[n][i].distance;
    if (ans != INF)
        cout<<ans;
    else cout<<-1;
    cout<<endl;
    return 0;
}
