#include <iostream>
#include <stdio.h>
#define INF 1000000001
using namespace std;

struct DATA{
    int ed,dist;
} cities[101];

int n,tmpans;
int dist[101][101];

void solve(int num)
{
    for (int i=0;i<n;i++)
    {
        cities[i].ed=i;
        cities[i].dist=dist[num][i];
    }
    DATA tmp;
    tmp=cities[num];
    cities[num]=cities[0];
    cities[0]=tmp;
    tmpans=0;
    for (int i=1;i<n;i++)
    {
        int mindist=cities[i].dist;
        int minnum=i;
        for (int k=i+1;k<n;k++)
            if (cities[k].dist<mindist)
        {
            mindist=cities[k].dist;
            minnum=k;
        }
        tmp=cities[minnum];
        cities[minnum]=cities[i];
        cities[i]=tmp;
        tmpans+=cities[i].dist;
        for (int k=i+1;k<n;k++)
            if (dist[cities[i].ed][cities[k].ed] < cities[k].dist)
                cities[k].dist=dist[cities[i].ed][cities[k].ed];
    }
}

int main()
{
    FILE *fp;
    fp=fopen("1.txt","r");
    while (fscanf(fp,"%d",&n) != EOF)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                fscanf(fp,"%d",&(dist[i][j]));
        int ans=INF;
        for (int i=0;i<n;i++)
        {
            solve(i);
            if (tmpans<ans)
                ans=tmpans;
        }
        cout<<ans<<endl;
    }
    return 0;
}
