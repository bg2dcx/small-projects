#include <iostream>
#include <memory.h>
#define INF 10000000

using namespace std;

int dist[101][101];
int n;
int spfaqueue[110];
int spfadist[110];
bool inQueue[110];

int solve(int st)
{
    memset(inQueue,0,sizeof(inQueue));
    for (int i=1;i<=n;i++)
        spfadist[i]=INF;
    spfadist[st]=0;
    inQueue[st]=0;
    spfaqueue[0]=st;
    int head=0, tail=1;
    while (head != tail)
    {
        int current=spfaqueue[head];
        for (int i=1;i<=n;i++)
            if (i != current && dist[current][i] != 0)
        {
            if (spfadist[current]+dist[current][i]<spfadist[i])
            {
                spfadist[i]=spfadist[current]+dist[current][i];
                if (!inQueue[i])
                {
                    inQueue[i]=true;
                    spfaqueue[tail]=i;
                    tail=(tail+1)%110;
                }
            }
        }
        head=(head+1)%110;
    }
    int maxi=0;
    for (int i=1;i<=n;i++)
        if (spfadist[i]>maxi)
         maxi=spfadist[i];
    return maxi;
}

int main()
{
    cin>>n;
    while ( n != 0)
    {
        memset(dist,0,sizeof(dist));
        for (int i=1;i<=n;i++)
        {
            int m;
            cin>>m;
            for (int j=0;j<m;j++)
            {
                int tmp;
                cin>>tmp;
                cin>>dist[i][tmp];
            }
        }
        int ans=INF;
        int ansnum=-1;
        for (int i=1;i<=n;i++)
        {
            int tmp=solve(i);
            if (tmp<ans)
            {
                ans=tmp;
                ansnum=i;
            }
        }
        cout<<ansnum<<' '<<ans<<endl;
        cin>>n;
    }
    return 0;
}
