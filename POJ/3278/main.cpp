#include <iostream>

using namespace std;
int bfsqueue[200001];
int dist[200001];
int head,tail,n,k;

int main()
{
    cin>>n>>k;
    int maxdist=100000;
    for (int i=0;i<=maxdist;i++)
        dist[i]=200001;
    dist[n]=0;
    head=0;tail=1;
    bfsqueue[0]=n;
    while (head<tail)
    {
        int current=bfsqueue[head];
        if (current == k)
        {
            cout<<dist[current]<<endl;
            return 0;
        }
        if (current-1>=0)
        {
            int tmp=current-1;
            if (dist[current]+1<dist[tmp])
            {
                dist[tmp]=dist[current]+1;
                bfsqueue[tail]=tmp;
                tail++;
            }
        }
        if (current+1<=maxdist)
        {
            int tmp=current+1;
            if (dist[current]+1<dist[tmp])
            {
                dist[tmp]=dist[current]+1;

                bfsqueue[tail]=tmp;
                tail++;
            }
        }
        if (current*2<=maxdist)
        {
            int tmp=current*2;
            if (dist[current]+1<dist[tmp])
            {
                dist[tmp]=dist[current]+1;

                bfsqueue[tail]=tmp;
                tail++;
            }
        }
        head++;
    }
    return 0;
}
