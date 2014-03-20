#include <iostream>
#define MAXN 501
#define MAXDIST 25000001

using namespace std;
int edge[501][501];
int dist[501];
bool inqueue[501];
bool cover[MAXN];
int spfaqueue[501];
int inquenum[501];
int numOfFarms,n,m,w;

void init()
{
    for (int i=0;i<MAXN;i++)
    {
        cover[i]=false;
        for (int j=0;j<MAXN;j++)
            edge[i][j]=MAXDIST;
    }
}

bool spfa(int stNum)
{
    for (int i=1;i<=n;i++)
    {
        dist[i]=MAXDIST;
        inquenum[i]=0;
        inqueue[i]=false;
    }
    int head=0;
    int tail=1;
    inqueue[stNum]=true;
    inquenum[stNum]=1;
    spfaqueue[0]=stNum;
    dist[stNum]=0;
    cover[stNum]=true;
    while (head!=tail)
    {
        int current=spfaqueue[head];
        for (int i=1;i<=n;i++)
            if (dist[current]+edge[current][i]<dist[i])
        {
            dist[i]=dist[current]+edge[current][i];
            inquenum[i]++;
            cover[i]=true;
            if (inquenum[i]>n)
                return true;
            if (!inqueue[i])
            {
                inqueue[i]=true;
                spfaqueue[tail]=i;
                tail=(tail+1)%MAXN;
            }
        }
        inqueue[current]=false;
        head=(head+1)%MAXN;
    }
    return false;
}

int main()
{
    cin>>numOfFarms;
    for (int i=0;i<numOfFarms;i++)
    {
        cin>>n>>m>>w;
        init();
        int st,ed,dis;
        for (int j=0;j<m;j++)
        {
            cin>>st>>ed>>dis;
            if (dis<edge[st][ed])
            {
                edge[st][ed]=dis;
                edge[ed][st]=dis;
            }
        }
        for (int j=0;j<w;j++)
        {
            cin>>st>>ed>>dis;
            if (-dis<edge[st][ed])
                edge[st][ed]=-dis;
        }
        bool findAns=false;
        for (int j=1;j<=n;j++)
            if (!cover[j])
            {
                findAns=spfa(j);
                if  (findAns) break;
            }
        if (findAns) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
