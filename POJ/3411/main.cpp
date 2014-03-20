#include <iostream>
#include <memory.h>
#include <fstream>
#define INF 1000000
#define MAXN 81920
using namespace std;

ifstream fin("1.txt");

struct ROAD
{
    int st,ed,mid,m1,m2;
    void init()
    {
        fin>>st>>ed>>mid>>m1>>m2;
    }
} roads[20];

struct DATA
{
    int city;
    int record;
} spfaqueue[2048*40];

bool inQueue[11][2048];
int price[11][2048];


int n,m;

bool check(int num, int rec)
{
    if ((rec & (1<<(num-1)))!=0)
        return true;
    else return false;
}

int main()
{
    fin>>n>>m;
    if ( n == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=1;i<=m;i++)
    {
        roads[i].init();
    }
    for (int i=1;i<=n;i++)
    {
       for (int j=0;j<2048;j++)
        price[i][j]=INF;
    }
    int head=0,tail=1;
    price[1][1]=0;
    spfaqueue[0].city=1;
    spfaqueue[0].record=1;
    int ans=INF;
    memset(inQueue,0,sizeof(inQueue));
    inQueue[1][1]=true;
    while (head != tail)
    {
        int current=spfaqueue[head].city;
        int rec=spfaqueue[head].record;
        for (int i=1;i<=m;i++)
            if (roads[i].st == current)
        {
            int dest=roads[i].ed;
            int money=roads[i].m2;
            if (check(roads[i].mid,rec) && roads[i].m1<roads[i].m2)
            {
                money=roads[i].m1;
            }
            int destRec=rec|(1<<(dest-1));
            if (price[current][rec]+money<price[dest][destRec])
            {
                price[dest][destRec]=price[current][rec]+money;
                if (dest == n && price[dest][destRec]<ans)
                {
                    ans=price[dest][destRec];
                }
                if (!inQueue[dest][destRec])
                {
                    spfaqueue[tail].city=dest;
                    spfaqueue[tail].record=destRec;
                    tail=(tail+1)%MAXN;
                    inQueue[dest][destRec]=true;
                }
            }
        }
        inQueue[current][rec]=false;
        head=(head+1)%MAXN;
    }
    int tmp=INF;
    if (ans <tmp)
     cout<<ans<<endl;
    else cout<<"impossible"<<endl;

    return 0;
}
